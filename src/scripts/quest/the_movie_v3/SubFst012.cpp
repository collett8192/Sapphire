// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubFst012 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubFst012() : Sapphire::ScriptAPI::EventScript( 65574 ){}; 
  ~SubFst012() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000768
  //ACTOR1 = 1000214
  //ACTOR2 = 1000218
  //ACTOR3 = 1000238
  //ACTOR4 = 1000248
  //ITEM0 = 2000081
  //ITEM1 = 2000082
  //ITEM2 = 2000083
  //SEQ0ACTOR0 = 0
  //SEQ1ACTOR1 = 1
  //SEQ1ACTOR2 = 2
  //SEQ1ACTOR3 = 3
  //SEQ2ACTOR4 = 4
  //SEQ2ACTOR4NPCTRADENO = 99
  //SEQ2ACTOR4NPCTRADEOK = 100

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=PARSEMONTRET
        break;
      }
      //seq 1 event item ITEM0 = UI8CH max stack 1
      //seq 1 event item ITEM1 = UI8CL max stack 1
      //seq 1 event item ITEM2 = UI8DH max stack 1
      case 1:
      {
        if( actor == 1000214 || actorId == 1000214 ) // ACTOR1 = GURTHCID
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00001( player ); // Scene00001: Normal(Talk, TargetCanMove), id=GURTHCID
          }
        }
        if( actor == 1000218 || actorId == 1000218 ) // ACTOR2 = ADMIRANDA
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ADMIRANDA
          }
        }
        if( actor == 1000238 || actorId == 1000238 ) // ACTOR3 = ALARIC
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALARIC
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      //seq 255 event item ITEM1 = UI8BL max stack 1
      //seq 255 event item ITEM2 = UI8CH max stack 1
      case 255:
      {
        Scene00004( player ); // Scene00004: NpcTrade(Talk, TargetCanMove), id=CEINGULED
        // +Callback Scene00100: Normal(QuestReward, QuestComplete), id=unknown
        // +Callback Scene00099: Normal(None), id=unknown
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
        if( player.getQuestUI8BL( getId() ) == 1 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8CH( getId(), 0 );
          player.setQuestUI8CL( getId(), 0 );
          player.setQuestUI8DH( getId(), 0 );
          player.updateQuest( getId(), 255 );
          player.setQuestUI8BH( getId(), 1 );
          player.setQuestUI8BL( getId(), 1 );
          player.setQuestUI8CH( getId(), 1 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubFst012:65574 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=PARSEMONTRET" );
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
    player.sendDebug( "SubFst012:65574 calling Scene00001: Normal(Talk, TargetCanMove), id=GURTHCID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubFst012:65574 calling Scene00002: Normal(Talk, TargetCanMove), id=ADMIRANDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubFst012:65574 calling Scene00003: Normal(Talk, TargetCanMove), id=ALARIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubFst012:65574 calling Scene00004: NpcTrade(Talk, TargetCanMove), id=CEINGULED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00100( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00100( Entity::Player& player )
  {
    player.sendDebug( "SubFst012:65574 calling [BranchTrue]Scene00100: Normal(QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00099( player );
      }
    };
    player.playScene( getId(), 100, NONE, callback );
  }
  void Scene00099( Entity::Player& player )
  {
    player.sendDebug( "SubFst012:65574 calling [BranchChain]Scene00099: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
        player.finishQuest( getId() );
    };
    player.playScene( getId(), 99, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubFst012 );
