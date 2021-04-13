// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmc105 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmc105() : Sapphire::ScriptAPI::EventScript( 68862 ){}; 
  ~LucKmc105() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_3, 1 entries
  //SEQ_4, 2 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1029198
  //ACTOR1 = 1029199
  //ACTOR2 = 1029200
  //ACTOR3 = 1027741
  //CARRY0 = 7
  //EOBJECT0 = 2009863
  //EOBJECT1 = 2009864
  //LOCACTION0 = 5665
  //LOCACTORERSABEL = 1029399
  //LOCACTORMINFILIA = 1026572
  //LOCACTORRUNAR = 1028142
  //LOCBGMMUSICEX3HOPETHEME02 = 647
  //STATUS0 = 404

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029198 || param2 == 1029198 ) // ACTOR0 = RUNAR
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=RUNAR
          break;
        }
        if( param1 == 1029199 || param2 == 1029199 ) // ACTOR1 = RYNE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 1:
      {
        Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove, SystemTalk), id=RYNE
        break;
      }
      case 2:
      {
        if( param1 == 2009863 || param2 == 2009863 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            /*
            Scene00004( player ); // Scene00004: Normal(SystemTalk, CanCancel), id=unknown
            // +Callback Scene00005: Normal(SystemTalk), id=unknown
            */
            Scene00005( player ); // invest the status param
          }
          break;
        }
        if( param1 == 1029200 || param2 == 1029200 ) // ACTOR2 = RYNE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 3:
      {
        Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove, SystemTalk), id=RYNE
        break;
      }
      case 4:
      {
        if( param1 == 2009864 || param2 == 2009864 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            /*
            Scene00008( player ); // Scene00008: Normal(SystemTalk, CanCancel), id=unknown
            // +Callback Scene00009: Normal(SystemTalk), id=unknown
            */
            Scene00009( player );
          }
          break;
        }
        if( param1 == 1029200 || param2 == 1029200 ) // ACTOR2 = RYNE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1027741 || param2 == 1027741 ) // ACTOR3 = ERSABEL
        {
          Scene00011( player ); // Scene00011: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ERSABEL
          break;
        }
        if( param1 == 1029200 || param2 == 1029200 ) // ACTOR2 = RYNE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=RYNE
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
    player.updateQuest( getId(), 2 );
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
    player.updateQuest( getId(), 4 );
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
    player.sendDebug( "LucKmc105:68862 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmc105:68862 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=RUNAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmc105:68862 calling Scene00002: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmc105:68862 calling Scene00003: Normal(Talk, TargetCanMove, SystemTalk), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
      player.addStatusEffectByIdIfNotExist( 404, 45000, player, 0, true );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmc105:68862 calling Scene00004: Normal(SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00005( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmc105:68862 calling Scene00005: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
      player.removeSingleStatusEffectById( 404 );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmc105:68862 calling Scene00006: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmc105:68862 calling Scene00007: Normal(Talk, TargetCanMove, SystemTalk), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      player.addStatusEffectByIdIfNotExist( 404, 30000, player, 0, true );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmc105:68862 calling Scene00008: Normal(SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00009( player );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmc105:68862 calling Scene00009: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
      player.removeSingleStatusEffectById( 404 );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmc105:68862 calling Scene00010: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmc105:68862 calling Scene00011: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ERSABEL" );
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
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmc105:68862 calling Scene00012: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmc105 );
