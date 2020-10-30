// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda123 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda123() : Sapphire::ScriptAPI::EventScript( 67993 ){}; 
  ~StmBda123() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_2, 2 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1020376
  //ACTOR1 = 1020375
  //ACTOR10 = 1020842
  //ACTOR2 = 1020377
  //ACTOR3 = 1020374
  //ACTOR4 = 1020373
  //ACTOR5 = 1020379
  //ACTOR6 = 1020378
  //ACTOR7 = 1020360
  //ACTOR8 = 1020362
  //ACTOR9 = 1020508
  //BINDACTOR01 = 6830045
  //BINDACTOR02 = 6836887
  //LOCACTION01 = 804
  //LOCACTOR01 = 1018509
  //LOCACTOR02 = 1019543
  //LOCACTOR03 = 1021687
  //LOCACTOR04 = 1021688
  //LOCACTOR05 = 1021689
  //LOCACTOR06 = 1021690
  //POPRANGE0 = 6836944

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MEFFRID
        break;
      }
      case 1:
      {
        if( param1 == 1020375 || param2 == 1020375 ) // ACTOR1 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=LYSE
          }
        }
        if( param1 == 1020376 || param2 == 1020376 ) // ACTOR0 = MEFFRID
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=MEFFRID
        }
        if( param1 == 1020377 || param2 == 1020377 ) // ACTOR2 = WISCAR
        {
          Scene00004( player ); // Scene00004: Normal(Talk), id=WISCAR
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020374 || param2 == 1020374 ) // ACTOR3 = MEFFRID
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=MEFFRID
          }
        }
        if( param1 == 1020373 || param2 == 1020373 ) // ACTOR4 = LYSE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=LYSE
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020379 || param2 == 1020379 ) // ACTOR5 = MEFFRID
        {
          Scene00007( player ); // Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MEFFRID
        }
        if( param1 == 1020378 || param2 == 1020378 ) // ACTOR6 = LYSE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020360 || param2 == 1020360 ) // ACTOR7 = WISCAR
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=WISCAR
        }
        if( param1 == 1020362 || param2 == 1020362 ) // ACTOR8 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        if( param1 == 1020508 || param2 == 1020508 ) // ACTOR9 = BEWILDEREDWOMEN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=BEWILDEREDWOMEN
        }
        if( param1 == 1020842 || param2 == 1020842 ) // ACTOR10 = SHARPEYEDWOMEN
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=SHARPEYEDWOMEN
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda123:67993 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda123:67993 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda123:67993 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda123:67993 calling Scene00003: Normal(Talk, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda123:67993 calling Scene00004: Normal(Talk), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda123:67993 calling Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda123:67993 calling Scene00006: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda123:67993 calling Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MEFFRID" );
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

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda123:67993 calling Scene00008: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda123:67993 calling Scene00009: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda123:67993 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda123:67993 calling Scene00011: Normal(Talk, TargetCanMove), id=BEWILDEREDWOMEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda123:67993 calling Scene00012: Normal(Talk, TargetCanMove), id=SHARPEYEDWOMEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda123 );
