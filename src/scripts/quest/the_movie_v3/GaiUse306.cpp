// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse306 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse306() : Sapphire::ScriptAPI::EventScript( 66983 ){}; 
  ~GaiUse306() = default; 

  //SEQ_0, 1 entries
  //SEQ_255, 2 entries

  //ACTIONTIMELINEEVENTBASESADOVER = 924
  //ACTIONTIMELINEEVENTLINK = 1002
  //ACTIONTIMELINEFACIALCRY = 612
  //ACTIONTIMELINEFACIALSMILE = 605
  //ACTOR0 = 1009057
  //ACTOR1 = 1008579
  //ACTOR2 = 1009089
  //EVENTACTIONSEARCH = 1
  //LOCACTOR0 = 1009238
  //LOCACTOR1 = 2621120
  //LOCACTOR2 = 1008175
  //LOCSE01 = 42
  //POPRANGE0 = 4894865
  //QSTCOMPCHK01 = 67063
  //QSTCOMPCHK02 = 67064
  //QSTCOMPCHK03 = 67065

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 255:
      {
        if( actor == 1008579 || actorId == 1008579 ) // ACTOR1 = MINFILIA
        {
          Scene00002( player ); // Scene00002: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MINFILIA
        }
        if( actor == 1009089 || actorId == 1009089 ) // ACTOR2 = MESSENGER01447
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=MESSENGER01447
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
    onProgress( player, npcId, 0, 2, 0 );
  }

  void onWithinRange( Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z ) override
  {
    onProgress( player, param1, param1, 3, param1 );
  }

private:
  void checkProgressSeq0( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse306:66983 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse306:66983 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse306:66983 calling Scene00002: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse306:66983 calling Scene00003: Normal(Talk, TargetCanMove), id=MESSENGER01447" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse306 );
