// FFXIVTheMovie.ParserV3.6
// param used:
//SCENE_2 = ESTINIEN
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna335 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna335() : Sapphire::ScriptAPI::EventScript( 67172 ){}; 
  ~HeaVna335() = default; 

  //SEQ_0, 2 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1014110
  //ACTOR1 = 1013172
  //ACTOR2 = 1012750
  //ACTOR3 = 1012748
  //CUTSCENEN01 = 846
  //CUTSCENEN02 = 847
  //CUTSCENEN03 = 848
  //CUTSCENEN04 = 849
  //CUTSCENEN05 = 850
  //LOCMUSIC0 = 83
  //POPRANGE0 = 5861454

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1014110 || param2 == 1014110 ) // ACTOR0 = ESTINIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, AutoFadeIn), id=ESTINIEN
            // +Callback Scene00002: Normal(CutScene, AutoFadeIn), id=ESTINIEN
          }
          break;
        }
        if( param1 == 1013172 || param2 == 1013172 ) // ACTOR1 = ICEHEART
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012750 || param2 == 1012750 ) // ACTOR2 = HAURCHEFANT
        {
          Scene00004( player ); // Scene00004: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HAURCHEFANT
          break;
        }
        if( param1 == 1012748 || param2 == 1012748 ) // ACTOR3 = ESTINIEN
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ESTINIEN
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna335:67172 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna335:67172 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, AutoFadeIn), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna335:67172 calling Scene00002: Normal(CutScene, AutoFadeIn), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna335:67172 calling Scene00003: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna335:67172 calling Scene00004: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HAURCHEFANT" );
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
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna335:67172 calling Scene00005: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna335 );
