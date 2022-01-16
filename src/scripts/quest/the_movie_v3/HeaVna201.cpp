// FFXIVTheMovie.ParserV3.6
// param used:
//SCENE_3 = dummyt0
//SCENE_4 = dummyt0
//SCENE_11 = ALPHINAUD2
//PRIVATE_SCENE5 = 198
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna201 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna201() : Sapphire::ScriptAPI::EventScript( 67135 ){}; 
  ~HeaVna201() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 4 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1012387
  //ACTOR1 = 1013197
  //ACTOR2 = 1001029
  //ACTOR3 = 1014322
  //ACTOR4 = 1013018
  //ACTOR5 = 1013021
  //ACTOR6 = 1013019
  //ACTOR7 = 1012192
  //ACTOR8 = 1002694
  //LOCACTORA = 1008181
  //LOCACTORE = 1004717
  //LOCACTORM = 1008183
  //LOCPOSE001 = 5866090
  //LOCPOSPC001 = 5866005
  //NCUTHEAVNA20110 = 799
  //POPRANGE0 = 5866506
  //TERRITORYTYPE0 = 198

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012387 || param2 == 1012387 ) // ACTOR0 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1013197 || param2 == 1013197 ) // ACTOR1 = TATARU
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 1:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = dummyt0
        {
          Scene00003( player ); // Scene00003: Normal(CutScene, AutoFadeIn), id=dummyt0
          // +Callback Scene00004: Normal(Talk, FadeIn), id=dummyt0
          break;
        }
        if( param1 == 1001029 || param2 == 1001029 ) // ACTOR2 = ZANTHAEL
        {
          Scene00005( player ); // Scene00005: Normal(Talk, YesNo, TargetCanMove), id=ZANTHAEL
          break;
        }
        if( param1 == 1014322 || param2 == 1014322 ) // ACTOR3 = ALPHINAUD
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1013197 || param2 == 1013197 ) // ACTOR1 = TATARU
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1013018 || param2 == 1013018 ) // ACTOR4 = HIGIRI
        {
          Scene00008( player ); // Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIGIRI
          break;
        }
        if( param1 == 1013021 || param2 == 1013021 ) // ACTOR5 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1013019 || param2 == 1013019 ) // ACTOR6 = EYNZAHRSLAFYRSYN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=EYNZAHRSLAFYRSYN
          break;
        }
        if( param1 == 1012192 || param2 == 1012192 ) // ACTOR7 = ALPHINAUD2
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD2
          break;
        }
        if( param1 == 1002694 || param2 == 1002694 ) // ACTOR8 = MERLWYB
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=MERLWYB
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
    player.sendDebug( "emote: {}", emoteId );
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna201:67135 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna201:67135 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna201:67135 calling Scene00002: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna201:67135 calling Scene00003: Normal(CutScene, AutoFadeIn), id=dummyt0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00004( Entity::Player& player ) //SEQ_1: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna201:67135 calling Scene00004: Normal(Talk, FadeIn), id=dummyt0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna201:67135 calling Scene00005: Normal(Talk, YesNo, TargetCanMove), id=ZANTHAEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 198 );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna201:67135 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna201:67135 calling Scene00007: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna201:67135 calling Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIGIRI" );
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

  void Scene00009( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna201:67135 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna201:67135 calling Scene00010: Normal(Talk, TargetCanMove), id=EYNZAHRSLAFYRSYN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna201:67135 calling Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna201:67135 calling Scene00012: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna201 );
