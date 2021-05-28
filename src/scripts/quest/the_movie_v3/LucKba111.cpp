// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKba111 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKba111() : Sapphire::ScriptAPI::EventScript( 68780 ){}; 
  ~LucKba111() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 4 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1029889
  //ACTOR1 = 1029893
  //ACTOR2 = 1029895
  //ACTOR3 = 1029896
  //ACTOR4 = 1029894
  //ACTOR5 = 1029897
  //EVENTPICTRUELUCKBA11101 = 798
  //EVENTPICTRUELUCKBA11102 = 799
  //EVENTPICTRUELUCKBA11103 = 800
  //LOCACTOR01 = 1028190
  //LOCBGM01 = 649
  //LOCBGM02 = 90
  //LOCIDLE01 = 985

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GRANSON
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=GRANSON
        break;
      }
      case 2:
      {
        if( param1 == 1029895 || param2 == 1029895 ) // ACTOR2 = SCAREDVILLAGER03244
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=SCAREDVILLAGER03244
            // +Callback Scene00004: Normal(Talk, TargetCanMove), id=SCAREDVILLAGER03244
          }
          break;
        }
        if( param1 == 1029896 || param2 == 1029896 ) // ACTOR3 = DISGUSTINGVILLAGER03244
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=DISGUSTINGVILLAGER03244
            // +Callback Scene00006: Normal(Talk, TargetCanMove), id=DISGUSTINGVILLAGER03244
          }
          break;
        }
        if( param1 == 1029894 || param2 == 1029894 ) // ACTOR4 = GRANSON
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=GRANSON
          break;
        }
        if( param1 == 1029897 || param2 == 1029897 ) // ACTOR5 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029893 || param2 == 1029893 ) // ACTOR1 = GRANSON
        {
          Scene00009( player ); // Scene00009: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=GRANSON
          break;
        }
        if( param1 == 1029895 || param2 == 1029895 ) // ACTOR2 = SCAREDVILLAGER03244
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=SCAREDVILLAGER03244
          break;
        }
        if( param1 == 1029896 || param2 == 1029896 ) // ACTOR3 = DISGUSTINGVILLAGER03244
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=DISGUSTINGVILLAGER03244
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
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKba111:68780 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKba111:68780 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKba111:68780 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKba111:68780 calling Scene00003: Normal(Talk, TargetCanMove), id=SCAREDVILLAGER03244" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKba111:68780 calling Scene00004: Normal(Talk, TargetCanMove), id=SCAREDVILLAGER03244" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKba111:68780 calling Scene00005: Normal(Talk, TargetCanMove), id=DISGUSTINGVILLAGER03244" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKba111:68780 calling Scene00006: Normal(Talk, TargetCanMove), id=DISGUSTINGVILLAGER03244" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKba111:68780 calling Scene00007: Normal(Talk, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKba111:68780 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKba111:68780 calling Scene00009: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=GRANSON" );
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
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKba111:68780 calling Scene00010: Normal(Talk, TargetCanMove), id=SCAREDVILLAGER03244" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKba111:68780 calling Scene00011: Normal(Talk, TargetCanMove), id=DISGUSTINGVILLAGER03244" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKba111 );
