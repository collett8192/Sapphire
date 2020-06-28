// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubFst024 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubFst024() : Sapphire::ScriptAPI::EventScript( 65635 ){}; 
  ~SubFst024() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000324
  //ACTOR1 = 1000100
  //ENEMY0 = 2313265
  //EOBJECT0 = 2000009
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONWAITING2MIDDLE = 12
  //ITEM0 = 2000076
  //LOCFACE1 = 617
  //LOCFACE2 = 604
  //MOTION0 = 1
  //MOTION1 = 34
  //NQCHARA01 = 1001503
  //NQCHARA02 = 1001504
  //NQCHARA03 = 1001505
  //NQCHARANONAME = 1006185
  //NQPOINT001 = 1556884
  //NQPOINT002 = 1556885
  //NQPOINT003 = 2029185
  //NQPOINT1000 = 2154510
  //NQPOINT1001 = 2154536
  //NQPOINT1002 = 2154537
  //NQPOINT1003 = 2154514
  //NQPOINT1004 = 2154513
  //NQPOINT1005 = 2154542
  //NQPOINT1006 = 2154543

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=EMERIA
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( actor == 2000009 || actorId == 2000009 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00001( player ); // Scene00001: Normal(None), id=unknown
            // +Callback Scene00002: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 2313265 || actorId == 2313265 ) // ENEMY0 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        Scene00004( player ); // Scene00004: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=EMERIA
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        Scene00006( player ); // Scene00006: Normal(None), id=unknown
        // +Callback Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MIOUNNE
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
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubFst024:65635 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=EMERIA" );
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
    player.sendDebug( "SubFst024:65635 calling Scene00001: Normal(None), id=unknown" );
    Scene00002( player );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubFst024:65635 calling [BranchTrue]Scene00002: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubFst024:65635 calling Scene00003: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubFst024:65635 calling Scene00004: NpcTrade(Talk, TargetCanMove), id=unknown" );
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
    player.sendDebug( "SubFst024:65635 calling [BranchTrue]Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=EMERIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubFst024:65635 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubFst024:65635 calling [BranchTrue]Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MIOUNNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubFst024 );
