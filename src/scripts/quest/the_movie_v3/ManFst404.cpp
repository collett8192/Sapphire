// FFXIVTheMovie.ParserV3.4
// id hint used:
//WARP_LIONNELLAIS = 132|22.43|-19|115.729|0|false
//PRIVATE_SCENE1 = 331
//PRIVATE_SCENE4 = 331
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ManFst404 : public Sapphire::ScriptAPI::EventScript
{
public:
  ManFst404() : Sapphire::ScriptAPI::EventScript( 66055 ){}; 
  ~ManFst404() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 1 entries
  //SEQ_3, 1 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1006492
  //ACTOR1 = 1000106
  //ACTOR2 = 1007690
  //ACTOR4 = 1006730
  //ACTOR5 = 1004433
  //CONTENTSTART = 20003
  //CUTSCENE01 = 104
  //CUTSCENE02 = 105
  //CUTSCENE03 = 106
  //CUTSCENE04WOL = 107
  //CUTSCENE05 = 372
  //CUTSCENEAFTER01 = 108
  //CUTSCENEAFTER02 = 286
  //INSTANCEDUNGEON0 = 20003
  //POPRANGE0 = 4103392
  //POPRANGE1 = 4313619
  //POPRANGE2 = 4332853
  //POPRANGE3 = 4103351
  //SCREENIMAGEUNLOCK = 115
  //TERRITORYTYPE0 = 132
  //TERRITORYTYPE1 = 331
  //TERRITORYTYPE2 = 130
  //UNLOCKADDNEWCONTENTTOCF = 3702

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1006492 || param2 == 1006492 ) // ACTOR0 = CID
        {
          Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=CID
          // +Callback Scene00001: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1000106 || param2 == 1000106 ) // ACTOR1 = LIONNELLAIS
        {
          Scene00002( player ); // Scene00002: Normal(Talk, YesNo, TargetCanMove), id=LIONNELLAIS
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1007690 || param2 == 1007690 ) // ACTOR2 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, Message, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1006492 || param2 == 1006492 ) // ACTOR0 = CID
        {
          Scene00004( player ); // Scene00004: Normal(Talk, YesNo, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1000106 || param2 == 1000106 ) // ACTOR1 = LIONNELLAIS
        {
          Scene00005( player ); // Scene00005: Normal(Talk, YesNo, TargetCanMove), id=LIONNELLAIS
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1007690 || param2 == 1007690 ) // ACTOR2 = ALPHINAUD
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 3:
      {
        if( type != 2 ) Scene00007( player ); // Scene00007: Normal(CutScene, AutoFadeIn), id=unknown
        break;
      }
      case 255:
      {
        if( param1 == 1006730 || param2 == 1006730 ) // ACTOR4 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1004433 || param2 == 1004433 ) // ACTOR5 = ELYENORA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, YesNo, TargetCanMove), id=ELYENORA
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "ManFst404:66055 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=CID" );
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
    player.sendDebug( "ManFst404:66055 calling Scene00001: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.enterPredefinedPrivateInstance( 331 );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "ManFst404:66055 calling Scene00002: Normal(Talk, YesNo, TargetCanMove), id=LIONNELLAIS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 132, 22.43f, -19.0f, 115.73f, 0.0f, false );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "ManFst404:66055 calling Scene00003: Normal(Talk, Message, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "ManFst404:66055 calling Scene00004: Normal(Talk, YesNo, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 331 );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "ManFst404:66055 calling Scene00005: Normal(Talk, YesNo, TargetCanMove), id=LIONNELLAIS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 132, 22.43f, -19.0f, 115.73f, 0.0f, false );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "ManFst404:66055 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "ManFst404:66055 calling Scene00007: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "ManFst404:66055 calling Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "ManFst404:66055 calling Scene00009: Normal(Talk, YesNo, TargetCanMove), id=ELYENORA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }
};

EXPOSE_SCRIPT( ManFst404 );
