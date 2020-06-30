// FFXIVTheMovie.ParserV3
//fix: skip dungeon
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna506 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna506() : Sapphire::ScriptAPI::EventScript( 67183 ){}; 
  ~HeaVna506() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 5 entries
  //SEQ_3, 5 entries
  //SEQ_4, 5 entries
  //SEQ_5, 6 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1014570
  //ACTOR1 = 1014571
  //ACTOR10 = 1014622
  //ACTOR11 = 1014573
  //ACTOR12 = 1014564
  //ACTOR2 = 1012064
  //ACTOR3 = 1014569
  //ACTOR4 = 1013386
  //ACTOR5 = 1013387
  //ACTOR6 = 1013099
  //ACTOR7 = 1013388
  //ACTOR8 = 5010000
  //ACTOR9 = 1014575
  //BINDALSOTO = 5859379
  //BINDALZEN = 5931637
  //CUTHEAVNA50610 = 867
  //CUTHEAVNA50620 = 868
  //CUTHEAVNA50630 = 869
  //CUTHEAVNA50640 = 870
  //INSTANCEDUNGEON0 = 20033
  //POPRANGE0 = 5861511
  //TERRITORYTYPE0 = 401
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKDUNGEONBISMARCK = 314

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1014570 || actorId == 1014570 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1014571 || actorId == 1014571 ) // ACTOR1 = CID
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=CID
        }
        break;
      }
      case 1:
      {
        if( actor == 1012064 || actorId == 1012064 ) // ACTOR2 = SONUVANU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=SONUVANU
          }
        }
        if( actor == 1014569 || actorId == 1014569 ) // ACTOR3 = ALPHINAUD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1014571 || actorId == 1014571 ) // ACTOR1 = CID
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=CID
        }
        break;
      }
      case 2:
      {
        if( actor == 1013386 || actorId == 1013386 ) // ACTOR4 = CID
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=CID
          }
        }
        if( actor == 1013387 || actorId == 1013387 ) // ACTOR5 = WEDGE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1013099 || actorId == 1013099 ) // ACTOR6 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013388 || actorId == 1013388 ) // ACTOR7 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( actor == 1012064 || actorId == 1012064 ) // ACTOR2 = SONUVANU
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=SONUVANU
        }
        break;
      }
      case 3:
      {
        if( actor == 1013387 || actorId == 1013387 ) // ACTOR5 = WEDGE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, YesNo, Message, TargetCanMove), id=WEDGE
          }
        }
        if( actor == 1013386 || actorId == 1013386 ) // ACTOR4 = CID
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1013099 || actorId == 1013099 ) // ACTOR6 = ALPHINAUD
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013388 || actorId == 1013388 ) // ACTOR7 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        if( actor == 1012064 || actorId == 1012064 ) // ACTOR2 = SONUVANU
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=SONUVANU
        }
        break;
      }
      case 4:
      {
        if( actor == 1013099 || actorId == 1013099 ) // ACTOR6 = ALPHINAUD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013387 || actorId == 1013387 ) // ACTOR5 = WEDGE
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1013388 || actorId == 1013388 ) // ACTOR7 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
        }
        if( actor == 1013386 || actorId == 1013386 ) // ACTOR4 = CID
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1012064 || actorId == 1012064 ) // ACTOR2 = SONUVANU
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=SONUVANU
        }
        break;
      }
      case 5:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00021( player ); // Scene00021: Normal(CutScene), id=unknown
        }
        if( actor == 1013099 || actorId == 1013099 ) // ACTOR6 = ALPHINAUD
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013386 || actorId == 1013386 ) // ACTOR4 = CID
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1013387 || actorId == 1013387 ) // ACTOR5 = WEDGE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1013388 || actorId == 1013388 ) // ACTOR7 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
        }
        if( actor == 1012064 || actorId == 1012064 ) // ACTOR2 = SONUVANU
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=SONUVANU
        }
        break;
      }
      case 255:
      {
        if( actor == 1014575 || actorId == 1014575 ) // ACTOR9 = ALPHINAUD
        {
          Scene00027( player ); // Scene00027: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1014622 || actorId == 1014622 ) // ACTOR10 = CID
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1014573 || actorId == 1014573 ) // ACTOR11 = WEDGE
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1014564 || actorId == 1014564 ) // ACTOR12 = BIGGS
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1012064 || actorId == 1012064 ) // ACTOR2 = SONUVANU
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=SONUVANU
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
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna506:67183 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00002: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00003: Normal(Talk, TargetCanMove), id=SONUVANU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00005: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00006: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00007: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00010: Normal(Talk, TargetCanMove), id=SONUVANU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00011: Normal(Talk, YesNo, Message, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 != 501 )
      {
        //player.setQuestUI8AL( getId(), 1 );
        //checkProgressSeq3( player );
        Scene00021( player );
      }
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00012: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00015: Normal(Talk, TargetCanMove), id=SONUVANU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00017: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00019: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00020: Normal(Talk, TargetCanMove), id=SONUVANU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00021: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00023: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00024: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00026: Normal(Talk, TargetCanMove), id=SONUVANU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00027: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00028: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00029: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00030: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVna506:67183 calling Scene00031: Normal(Talk, TargetCanMove), id=SONUVANU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna506 );
