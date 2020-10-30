// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda121 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda121() : Sapphire::ScriptAPI::EventScript( 67991 ){}; 
  ~StmBda121() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 4 entries
  //SEQ_3, 2 entries
  //SEQ_4, 2 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1020338
  //ACTOR1 = 1020366
  //ACTOR2 = 1020365
  //ACTOR3 = 1019478
  //ACTOR4 = 1020368
  //ACTOR5 = 1020367
  //ACTOR6 = 1020370
  //ACTOR7 = 1020369
  //ACTOR8 = 1020372
  //ACTOR9 = 1020371
  //BINDACTOR01 = 6829918
  //BINDACTOR02 = 6829980
  //BINDACTOR03 = 6830019
  //BINDACTOR04 = 6830027
  //BINDACTOR05 = 6866091
  //CUTSCENEN01 = 1388
  //LOCACTOR01 = 1018509
  //LOCACTOR02 = 1019543
  //POPRANGE0 = 6829981
  //TERRITORYTYPE0 = 620

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MEFFRID
        break;
      }
      case 1:
      {
        if( param1 == 1020366 || param2 == 1020366 ) // ACTOR1 = MEFFRID
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=MEFFRID
          }
        }
        if( param1 == 1020365 || param2 == 1020365 ) // ACTOR2 = LYSE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=LYSE
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00004( player ); // Scene00004: Normal(CutScene, Dismount), id=unknown
        }
        if( param1 == 1020366 || param2 == 1020366 ) // ACTOR1 = MEFFRID
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MEFFRID
        }
        if( param1 == 1020365 || param2 == 1020365 ) // ACTOR2 = LYSE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1019478 || param2 == 1019478 ) // ACTOR3 = ALAMHIGANGATEMAN02455
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALAMHIGANGATEMAN02455
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020368 || param2 == 1020368 ) // ACTOR4 = MEFFRID
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MEFFRID
          }
        }
        if( param1 == 1020367 || param2 == 1020367 ) // ACTOR5 = LYSE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=LYSE
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020370 || param2 == 1020370 ) // ACTOR6 = MEFFRID
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=MEFFRID
          }
        }
        if( param1 == 1020369 || param2 == 1020369 ) // ACTOR7 = LYSE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=LYSE
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020372 || param2 == 1020372 ) // ACTOR8 = MEFFRID
        {
          Scene00012( player ); // Scene00012: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=MEFFRID
        }
        if( param1 == 1020371 || param2 == 1020371 ) // ACTOR9 = LYSE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=LYSE
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda121:67991 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda121:67991 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda121:67991 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda121:67991 calling Scene00003: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    //player.sendDebug( "StmBda121:67991 calling Scene00004: Normal(CutScene, Dismount), id=unknown" );
    //auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    //{
      checkProgressSeq2( player );
    //};
    //player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda121:67991 calling Scene00005: Normal(Talk, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda121:67991 calling Scene00006: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda121:67991 calling Scene00007: Normal(Talk, TargetCanMove), id=ALAMHIGANGATEMAN02455" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda121:67991 calling Scene00008: Normal(Talk, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda121:67991 calling Scene00009: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda121:67991 calling Scene00010: Normal(Talk, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda121:67991 calling Scene00011: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda121:67991 calling Scene00012: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda121:67991 calling Scene00013: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda121 );
