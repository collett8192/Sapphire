// FFXIVTheMovie.ParserV3
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubFst052 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubFst052() : Sapphire::ScriptAPI::EventScript( 65694 ){}; 
  ~SubFst052() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000501
  //ACTOR1 = 1000473
  //ENEMY0 = 57
  //ITEM0 = 2000099
  //ITEM1 = 2000094
  //SEQ0ACTOR0 = 0
  //SEQ2ACTOR0 = 1
  //SEQ2ACTOR0NPCTRADENO = 99
  //SEQ2ACTOR0NPCTRADEOK = 100
  //SEQ3ACTOR1 = 2
  //SEQ3ACTOR1NPCTRADENO = 97
  //SEQ3ACTOR1NPCTRADEOK = 98

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=WALTHEOF
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 4
      case 1:
      {
        Scene00001( player ); // Scene00001: NpcTrade(Talk, TargetCanMove), id=WALTHEOF
        // +Callback Scene00100: Normal(Talk, TargetCanMove), id=WALTHEOF
        break;
      }
      //seq 2 event item ITEM1 = UI8BH max stack 1
      //seq 2 event item ITEM0 = UI8BL max stack 4
      case 2:
      {
        Scene00099( player ); // Scene00099: Normal(None), id=unknown
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack 1
      //seq 255 event item ITEM0 = UI8BL max stack 4
      case 255:
      {
        Scene00002( player ); // Scene00002: NpcTrade(Talk, TargetCanMove), id=MARGAULT
        // +Callback Scene00098: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MARGAULT
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

private:
  void checkProgressSeq0( Entity::Player& player )
  {
    player.updateQuest( getId(), 1 );
    player.setQuestUI8BH( getId(), 4 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
    player.setQuestUI8BH( getId(), 1 );
    player.setQuestUI8BL( getId(), 4 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubFst052:65694 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=WALTHEOF" );
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
    player.sendDebug( "SubFst052:65694 calling Scene00001: NpcTrade(Talk, TargetCanMove), id=WALTHEOF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00100( player );
      }
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00100( Entity::Player& player )
  {
    player.sendDebug( "SubFst052:65694 calling [BranchTrue]Scene00100: Normal(Talk, TargetCanMove), id=WALTHEOF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 100, NONE, callback );
  }

  void Scene00099( Entity::Player& player )
  {
    player.sendDebug( "SubFst052:65694 calling Scene00099: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubFst052:65694 calling Scene00002: NpcTrade(Talk, TargetCanMove), id=MARGAULT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00098( player );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00098( Entity::Player& player )
  {
    player.sendDebug( "SubFst052:65694 calling [BranchTrue]Scene00098: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MARGAULT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 98, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubFst052 );
