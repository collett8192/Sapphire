// FFXIVTheMovie.ParserV3
// id hint used:
//SCENE_2 = ALPHINAUD
//fix: black screen
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna507 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna507() : Sapphire::ScriptAPI::EventScript( 67184 ){}; 
  ~HeaVna507() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 7 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1014575
  //ACTOR1 = 1014564
  //ACTOR2 = 1014622
  //ACTOR3 = 1014573
  //ACTOR4 = 1013100
  //ACTOR5 = 1013102
  //ACTOR6 = 1013103
  //ACTOR7 = 1012064
  //ACTOR8 = 1012195
  //LOCACTIONNADERU = 848
  //LOCACTORAL = 1011887
  //LOCACTORBI = 5920875
  //LOCACTORENTA = 2006048
  //LOCACTORMAD = 1012494
  //LOCACTORRUKIA = 1008193
  //LOCACTORUE = 5931576
  //LOCMAKERENTA = 5923411
  //LOCMAKERMAD = 5931613
  //LOCMAKERRUKIA = 5938137
  //NCUTHEAVNA50710 = 871
  //POPRANGE0 = 5859454

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1014575 || actorId == 1014575 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
          // +Callback Scene00002: Normal(CutScene, FadeIn), id=ALPHINAUD
        }
        if( actor == 1014564 || actorId == 1014564 ) // ACTOR1 = BIGGS
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1014622 || actorId == 1014622 ) // ACTOR2 = CID
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1014573 || actorId == 1014573 ) // ACTOR3 = WEDGE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=WEDGE
        }
        break;
      }
      case 1:
      {
        if( actor == 1013100 || actorId == 1013100 ) // ACTOR4 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
        }
        if( actor == 1013102 || actorId == 1013102 ) // ACTOR5 = LUCIA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1013103 || actorId == 1013103 ) // ACTOR6 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        if( actor == 1014564 || actorId == 1014564 ) // ACTOR1 = BIGGS
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1014622 || actorId == 1014622 ) // ACTOR2 = CID
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1014573 || actorId == 1014573 ) // ACTOR3 = WEDGE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1012064 || actorId == 1012064 ) // ACTOR7 = SONUVANU
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=SONUVANU
        }
        break;
      }
      case 255:
      {
        if( actor == 1012195 || actorId == 1012195 ) // ACTOR8 = CID
        {
          Scene00013( player ); // Scene00013: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=CID
        }
        if( actor == 1014573 || actorId == 1014573 ) // ACTOR3 = WEDGE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1014564 || actorId == 1014564 ) // ACTOR1 = BIGGS
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1013100 || actorId == 1013100 ) // ACTOR4 = ALPHINAUD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013102 || actorId == 1013102 ) // ACTOR5 = LUCIA
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1013103 || actorId == 1013103 ) // ACTOR6 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna507:67184 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna507:67184 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna507:67184 calling [BranchChain]Scene00002: Normal(CutScene, FadeIn), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 401, -584.1, -52.4, -445.3, 2.88 );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna507:67184 calling Scene00003: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna507:67184 calling Scene00004: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna507:67184 calling Scene00005: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna507:67184 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna507:67184 calling Scene00007: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna507:67184 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna507:67184 calling Scene00009: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna507:67184 calling Scene00010: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna507:67184 calling Scene00011: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna507:67184 calling Scene00012: Normal(Talk, TargetCanMove), id=SONUVANU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna507:67184 calling Scene00013: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna507:67184 calling Scene00014: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna507:67184 calling Scene00015: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna507:67184 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna507:67184 calling Scene00017: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna507:67184 calling Scene00018: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( HeaVna507 );
