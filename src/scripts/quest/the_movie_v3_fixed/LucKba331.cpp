// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKba331 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKba331() : Sapphire::ScriptAPI::EventScript( 68812 ){}; 
  ~LucKba331() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 3 entries
  //SEQ_3, 2 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1030964
  //ACTOR1 = 1030144
  //ACTOR2 = 1030145
  //ACTOR3 = 1030146
  //CUTSCENE00 = 2103
  //CUTSCENE01 = 2104
  //EOBJECT0 = 2010404
  //EVENTACTION0 = 1
  //LEVELENPCID0 = 7963559
  //LOCACTOR0 = 1030128
  //LOGMES00 = 3744
  //QSTPIC0 = 818
  //QSTPIC1 = 819
  //QSTPIC2 = 820
  //QUESTBATTLE0 = 5034
  //TERRITORYTYPE0 = 875
  //TERRITORYTYPE1 = 817

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=LUEREEQ
        break;
      }
      case 1:
      {
        if( param1 == 1030144 || param2 == 1030144 ) // ACTOR1 = LUEREEQ
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove, Menu), id=LUEREEQ
          }
          break;
        }
        if( param1 == 1030145 || param2 == 1030145 ) // ACTOR2 = OLVARA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=OLVARA
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1030146 || param2 == 1030146 ) // ACTOR3 = LUEREEQ
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, QuestBattle, YesNo, Message, TargetCanMove, CanCancel), id=LUEREEQ
            // +Callback Scene00005: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1030145 || param2 == 1030145 ) // ACTOR2 = OLVARA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=OLVARA
          break;
        }
        if( param1 == 2010404 || param2 == 2010404 ) // EOBJECT0 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00009( player ); // Scene00009: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1030145 || param2 == 1030145 ) // ACTOR2 = OLVARA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=OLVARA
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030144 || param2 == 1030144 ) // ACTOR1 = LUEREEQ
        {
          Scene00011( player ); // Scene00011: Normal(Talk, NpcDespawn, QuestReward, QuestComplete, TargetCanMove), id=LUEREEQ
          break;
        }
        if( param1 == 1030145 || param2 == 1030145 ) // ACTOR2 = OLVARA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=OLVARA
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKba331:68812 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKba331:68812 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=LUEREEQ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKba331:68812 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove, Menu), id=LUEREEQ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKba331:68812 calling Scene00003: Normal(Talk, TargetCanMove), id=OLVARA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKba331:68812 calling Scene00004: Normal(Talk, QuestBattle, YesNo, Message, TargetCanMove, CanCancel), id=LUEREEQ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00005( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKba331:68812 calling Scene00005: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKba331:68812 calling Scene00006: Normal(Talk, TargetCanMove), id=OLVARA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKba331:68812 calling Scene00008: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKba331:68812 calling Scene00009: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKba331:68812 calling Scene00010: Normal(Talk, TargetCanMove), id=OLVARA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKba331:68812 calling Scene00011: Normal(Talk, NpcDespawn, QuestReward, QuestComplete, TargetCanMove), id=LUEREEQ" );
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
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKba331:68812 calling Scene00012: Normal(Talk, TargetCanMove), id=OLVARA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKba331 );
