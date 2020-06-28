// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse401 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse401() : Sapphire::ScriptAPI::EventScript( 65588 ){}; 
  ~GaiUse401() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_2, 3 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1008969
  //ACTOR1 = 1010078
  //ACTOR2 = 1009959
  //ACTOR3 = 1009960
  //ACTOR4 = 1008700
  //ACTOR5 = 1010709
  //CUTSCENEN01 = 606
  //CUTSCENEN02 = 607

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MINFILIA
        break;
      }
      case 1:
      {
        if( actor == 1010078 || actorId == 1010078 ) // ACTOR1 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
        }
        if( actor == 1008969 || actorId == 1008969 ) // ACTOR0 = MINFILIA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        if( actor == 1009959 || actorId == 1009959 ) // ACTOR2 = ILBERD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ILBERD
        }
        if( actor == 1009960 || actorId == 1009960 ) // ACTOR3 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( actor == 1009959 || actorId == 1009959 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1009960 || actorId == 1009960 ) // ACTOR3 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        if( actor == 1010078 || actorId == 1010078 ) // ACTOR1 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 255:
      {
        if( actor == 1008700 || actorId == 1008700 ) // ACTOR4 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( actor == 1009959 || actorId == 1009959 ) // ACTOR2 = ILBERD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ILBERD
        }
        if( actor == 1010709 || actorId == 1010709 ) // ACTOR5 = ROAILLE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ROAILLE
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
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse401:65588 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse401:65588 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse401:65588 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse401:65588 calling Scene00003: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse401:65588 calling Scene00004: Normal(Talk, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse401:65588 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse401:65588 calling Scene00006: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse401:65588 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse401:65588 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse401:65588 calling Scene00009: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse401:65588 calling Scene00010: Normal(Talk, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse401:65588 calling Scene00011: Normal(Talk, TargetCanMove), id=ROAILLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse401 );
