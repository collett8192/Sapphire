// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda103 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda103() : Sapphire::ScriptAPI::EventScript( 67984 ){}; 
  ~StmBda103() = default; 

  //SEQ_0, 8 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1020329
  //ACTOR1 = 1020324
  //ACTOR10 = 1020338
  //ACTOR2 = 1020325
  //ACTOR3 = 1020326
  //ACTOR4 = 1020327
  //ACTOR5 = 1020328
  //ACTOR6 = 1020330
  //ACTOR7 = 1020331
  //ACTOR8 = 1019466
  //ACTOR9 = 1020337
  //BINDACTOR01 = 6829422
  //BINDACTOR02 = 6829424
  //BINDACTOR03 = 6829425
  //BINDACTOR04 = 6829426
  //BINDACTOR05 = 6829427
  //BINDACTOR06 = 6829429
  //BINDACTOR07 = 6829430
  //CUTSCENEN01 = 1383

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020329 || param2 == 1020329 ) // ACTOR0 = CONRAD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CONRAD
        }
        if( param1 == 1020324 || param2 == 1020324 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020325 || param2 == 1020325 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020326 || param2 == 1020326 ) // ACTOR3 = LYSE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020327 || param2 == 1020327 ) // ACTOR4 = YSHTOLA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1020328 || param2 == 1020328 ) // ACTOR5 = KRILE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1020330 || param2 == 1020330 ) // ACTOR6 = MNAAGO
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=MNAAGO
        }
        if( param1 == 1020331 || param2 == 1020331 ) // ACTOR7 = MEFFRID
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MEFFRID
        }
        break;
      }
      case 255:
      {
        if( param1 == 1019466 || param2 == 1019466 ) // ACTOR8 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(CutScene), id=unknown
          // +Callback Scene00010: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( param1 == 1020337 || param2 == 1020337 ) // ACTOR9 = MNAAGO
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=MNAAGO
        }
        if( param1 == 1020338 || param2 == 1020338 ) // ACTOR10 = MEFFRID
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=MEFFRID
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda103:67984 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda103:67984 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda103:67984 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda103:67984 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda103:67984 calling Scene00004: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda103:67984 calling Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda103:67984 calling Scene00006: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda103:67984 calling Scene00007: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda103:67984 calling Scene00008: Normal(Talk, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda103:67984 calling Scene00009: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda103:67984 calling [BranchTrue]Scene00010: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda103:67984 calling Scene00011: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda103:67984 calling Scene00012: Normal(Talk, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda103 );
