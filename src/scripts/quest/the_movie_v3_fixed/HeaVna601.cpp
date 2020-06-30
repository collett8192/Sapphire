// FFXIVTheMovie.ParserV3
//fix: enter instance
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna601 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna601() : Sapphire::ScriptAPI::EventScript( 67186 ){}; 
  ~HeaVna601() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 9 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1013112
  //ACTOR1 = 1013111
  //ACTOR10 = 1013184
  //ACTOR11 = 1013185
  //ACTOR12 = 1013162
  //ACTOR13 = 1013128
  //ACTOR2 = 1013113
  //ACTOR3 = 1013114
  //ACTOR4 = 1013115
  //ACTOR5 = 1013116
  //ACTOR6 = 1013183
  //ACTOR7 = 1011223
  //ACTOR8 = 1013181
  //ACTOR9 = 1013182
  //CUTSCENEN01 = 874
  //POPRANGE0 = 5861351
  //POPRANGE1 = 5861401
  //QSTACTOR0 = 5862283
  //QSTACTOR1 = 5862285
  //QSTACTOR10 = 5859640
  //TERRITORYTYPE0 = 428

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1013112 || actorId == 1013112 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013111 || actorId == 1013111 ) // ACTOR1 = CID
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1013113 || actorId == 1013113 ) // ACTOR2 = LUCIA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1013114 || actorId == 1013114 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
        }
        if( actor == 1013115 || actorId == 1013115 ) // ACTOR4 = WEDGE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1013116 || actorId == 1013116 ) // ACTOR5 = BIGGS
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=BIGGS
        }
        break;
      }
      case 1:
      {
        if( actor == 1013183 || actorId == 1013183 ) // ACTOR6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1011223 || actorId == 1011223 ) // ACTOR7 = TEMPLEKIGHTGATE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, YesNo, TargetCanMove), id=TEMPLEKIGHTGATE
        }
        if( actor == 1013114 || actorId == 1013114 ) // ACTOR3 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( actor == 1013115 || actorId == 1013115 ) // ACTOR4 = WEDGE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1013116 || actorId == 1013116 ) // ACTOR5 = BIGGS
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1013181 || actorId == 1013181 ) // ACTOR8 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013182 || actorId == 1013182 ) // ACTOR9 = CID
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1013184 || actorId == 1013184 ) // ACTOR10 = LUCIA
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1013185 || actorId == 1013185 ) // ACTOR11 = EDMONT
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=EDMONT
        }
        break;
      }
      case 255:
      {
        if( actor == 1013162 || actorId == 1013162 ) // ACTOR12 = TATARU
        {
          Scene00016( player ); // Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TATARU
        }
        if( actor == 1013128 || actorId == 1013128 ) // ACTOR13 = ALPHINAUD
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013182 || actorId == 1013182 ) // ACTOR9 = CID
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1013183 || actorId == 1013183 ) // ACTOR6 = AYMERIC
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( actor == 1013184 || actorId == 1013184 ) // ACTOR10 = LUCIA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1013185 || actorId == 1013185 ) // ACTOR11 = EDMONT
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=EDMONT
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
    player.sendDebug( "HeaVna601:67186 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna601:67186 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00002: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00003: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00005: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00006: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00007: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.exitInstance();
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00008: Normal(Talk, YesNo, TargetCanMove), id=TEMPLEKIGHTGATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 428 );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00010: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00011: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00013: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00014: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00015: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00018: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00019: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00020: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVna601:67186 calling Scene00021: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna601 );
