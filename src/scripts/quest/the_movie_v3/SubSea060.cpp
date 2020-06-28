// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea060 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea060() : Sapphire::ScriptAPI::EventScript( 66008 ){}; 
  ~SubSea060() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 8 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002628
  //ENEMY0 = 3930119
  //ENEMY1 = 3930282
  //ENEMY2 = 3930287
  //EOBJECT0 = 2001249
  //EOBJECT1 = 2001250
  //EOBJECT2 = 2001251
  //EOBJECT3 = 2001252
  //EOBJECT4 = 2001253
  //EVENTACTION = 31
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000351

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=BHIRDRAEG
        break;
      }
      //seq 1 event item ITEM0 = UI8DH max stack 3
      case 1:
      {
        if( actor == 2001249 || actorId == 2001249 ) // EOBJECT0 = unknown
        {
          Scene00001( player ); // Scene00001: Normal(None), id=unknown
          // +Callback Scene00002: Normal(Message), id=unknown
        }
        if( actor == 3930119 || actorId == 3930119 ) // ENEMY0 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
        }
        if( actor == 2001250 || actorId == 2001250 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(None), id=unknown
            // +Callback Scene00005: Normal(None), id=unknown
          }
          else
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
          }
        }
        if( actor == 2001251 || actorId == 2001251 ) // EOBJECT2 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          // +Callback Scene00008: Normal(Message), id=unknown
        }
        if( actor == 3930282 || actorId == 3930282 ) // ENEMY1 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( actor == 2001252 || actorId == 2001252 ) // EOBJECT3 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          // +Callback Scene00011: Normal(Message), id=unknown
        }
        if( actor == 3930287 || actorId == 3930287 ) // ENEMY2 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        if( actor == 2001253 || actorId == 2001253 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(None), id=unknown
            // +Callback Scene00014: Normal(None), id=unknown
          }
          else
          {
            Scene00015( player ); // Scene00015: Normal(None), id=unknown
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 3
      case 255:
      {
        Scene00016( player ); // Scene00016: NpcTrade(Talk, TargetCanMove), id=BHIRDRAEG
        // +Callback Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BHIRDRAEG
        // +Callback Scene00018: Normal(None), id=unknown
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
      if( player.getQuestUI8BH( getId() ) == 1 )
      {
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8DH( getId(), 0 );
        player.updateQuest( getId(), 255 );
        player.setQuestUI8BH( getId(), 3 );
      }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubSea060:66008 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=BHIRDRAEG" );
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
    player.sendDebug( "SubSea060:66008 calling Scene00001: Normal(None), id=unknown" );
    Scene00002( player );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubSea060:66008 calling [BranchTrue]Scene00002: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubSea060:66008 calling Scene00003: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubSea060:66008 calling Scene00004: Normal(None), id=unknown" );
    Scene00005( player );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubSea060:66008 calling [BranchTrue]Scene00005: Normal(None), id=unknown" );
    Scene00006( player );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubSea060:66008 calling [BranchFalse]Scene00006: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubSea060:66008 calling Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubSea060:66008 calling [BranchTrue]Scene00008: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubSea060:66008 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubSea060:66008 calling Scene00010: Normal(None), id=unknown" );
    Scene00011( player );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubSea060:66008 calling [BranchTrue]Scene00011: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubSea060:66008 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubSea060:66008 calling Scene00013: Normal(None), id=unknown" );
    Scene00014( player );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "SubSea060:66008 calling [BranchTrue]Scene00014: Normal(None), id=unknown" );
    Scene00015( player );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "SubSea060:66008 calling [BranchFalse]Scene00015: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "SubSea060:66008 calling Scene00016: NpcTrade(Talk, TargetCanMove), id=BHIRDRAEG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00017( player );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "SubSea060:66008 calling [BranchTrue]Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BHIRDRAEG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00018( player );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "SubSea060:66008 calling [BranchChain]Scene00018: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
        player.finishQuest( getId() );
    };
    player.playScene( getId(), 18, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubSea060 );
