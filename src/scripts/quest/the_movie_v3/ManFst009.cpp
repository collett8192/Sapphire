// FFXIVTheMovie.ParserV3.3
// id hint used:
//_BRANCH SET!!
//PRIVATE_DOORMANLOTUS = 205
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ManFst009 : public Sapphire::ScriptAPI::EventScript
{
public:
  ManFst009() : Sapphire::ScriptAPI::EventScript( 65985 ){}; 
  ~ManFst009() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1000100
  //ACTOR1 = 1000286
  //ACTOR2 = 1000153
  //ACTOR3 = 1003027
  //ACTOR4 = 1000460
  //CUTSCENE01 = 62
  //CUTSCENE02 = 63
  //CUTSCENE03 = 68
  //POPRANGE0 = 4106221
  //POPRANGE1 = 3877982
  //RITEM0 = 2651
  //TERRITORYTYPE0 = 205

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MIOUNNE
        break;
      }
      case 1:
      {
        if( param1 == 1000286 || param2 == 1000286 ) // ACTOR1 = ESTAINE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ESTAINE
            // +Callback Scene00003: Normal(Talk, TargetCanMove), id=ESTAINE
            // +Callback Scene00004: Normal(CutScene, AutoFadeIn), id=unknown
          }
          else
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ESTAINE
          }
          break;
        }
        if( param1 == 1000153 || param2 == 1000153 ) // ACTOR2 = BEATINE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=BEATINE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1003027 || param2 == 1003027 ) // ACTOR3 = KANESENNA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KANESENNA
          break;
        }
        if( param1 == 1000460 || param2 == 1000460 ) // ACTOR4 = DOORMANLOTUS
        {
          Scene00008( player ); // Scene00008: Normal(Talk, YesNo, TargetCanMove), id=DOORMANLOTUS
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "ManFst009:65985 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "ManFst009:65985 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MIOUNNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "ManFst009:65985 calling Scene00002: Normal(Talk, TargetCanMove), id=ESTAINE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "ManFst009:65985 calling Scene00003: Normal(Talk, TargetCanMove), id=ESTAINE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "ManFst009:65985 calling Scene00004: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "ManFst009:65985 calling Scene00005: Normal(Talk, TargetCanMove), id=ESTAINE" );
    player.playScene( getId(), 5, NONE, nullptr );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "ManFst009:65985 calling Scene00006: Normal(Talk, TargetCanMove), id=BEATINE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "ManFst009:65985 calling Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KANESENNA" );
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
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "ManFst009:65985 calling Scene00008: Normal(Talk, YesNo, TargetCanMove), id=DOORMANLOTUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 205 );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }
};

EXPOSE_SCRIPT( ManFst009 );
