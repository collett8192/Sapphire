// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ManFst502 : public Sapphire::ScriptAPI::EventScript
{
public:
  ManFst502() : Sapphire::ScriptAPI::EventScript( 66672 ){}; 
  ~ManFst502() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 8 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006657
  //ACTOR2 = 1006662
  //ACTOR3 = 1006663
  //ACTOR4 = 1006664
  //ACTOR5 = 1006660
  //ACTOR6 = 1006661
  //ACTOR7 = 1007682
  //ACTOR8 = 1007683
  //CONTENTSTART = 15
  //CUTSCENE01 = 265
  //INSTANCEDUNGEON0 = 15
  //POPRANGE0 = 4332876
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKIMAGEDUNGEON = 98

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(CutScene, Message, QuestAccept), id=unknown
        break;
      }
      case 1:
      {
        if( actor == 1006662 || actorId == 1006662 ) // ACTOR2 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(None), id=unknown
        }
        if( actor == 1006663 || actorId == 1006663 ) // ACTOR3 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
        }
        if( actor == 1006664 || actorId == 1006664 ) // ACTOR4 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
        }
        if( actor == 1006660 || actorId == 1006660 ) // ACTOR5 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
        }
        if( actor == 1006661 || actorId == 1006661 ) // ACTOR6 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
        }
        if( actor == 1007682 || actorId == 1007682 ) // ACTOR7 = MINFILIA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        if( actor == 1007683 || actorId == 1007683 ) // ACTOR8 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1006657 || actorId == 1006657 ) // ACTOR0 = RAUBAHN
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=RAUBAHN
        }
        break;
      }
      case 255:
      {
        Scene00010( player ); // Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RAUBAHN
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "ManFst502:66672 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "ManFst502:66672 calling [BranchTrue]Scene00001: Normal(CutScene, Message, QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "ManFst502:66672 calling Scene00002: Normal(None), id=unknown" );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "ManFst502:66672 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "ManFst502:66672 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "ManFst502:66672 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "ManFst502:66672 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "ManFst502:66672 calling Scene00007: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "ManFst502:66672 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "ManFst502:66672 calling Scene00009: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "ManFst502:66672 calling Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }
};

EXPOSE_SCRIPT( ManFst502 );
