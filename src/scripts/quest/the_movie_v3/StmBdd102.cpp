// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdd102 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdd102() : Sapphire::ScriptAPI::EventScript( 68607 ){}; 
  ~StmBdd102() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 2 entries
  //SEQ_2, 3 entries
  //SEQ_3, 1 entries
  //SEQ_4, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1025557
  //ACTOR1 = 1025555
  //ACTOR2 = 1025556
  //ACTOR3 = 1019297
  //ACTOR4 = 1019303
  //BINDACTOR01 = 7350618
  //BINDACTOR02 = 7350619
  //EOBJECT0 = 2009474
  //EOBJECT1 = 2009527
  //EOBJECT2 = 2009528
  //EOBJECT3 = 2009475
  //EVENTACTION0 = 68
  //EVENTACTION1 = 41
  //EVENTACTION2 = 1
  //LOCACTION01 = 624
  //LOCACTOR01 = 1019544
  //LOCACTOR02 = 1019096
  //LOCOBJ01 = 2009476
  //NCUTEVENTSTMBDD10201 = 1694
  //POPRANGE0 = 7356097
  //POPRANGE1 = 7356098

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1025557 || param2 == 1025557 ) // ACTOR0 = HIEN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, AutoFadeIn), id=HIEN
          break;
        }
        if( param1 == 1025555 || param2 == 1025555 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1025556 || param2 == 1025556 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019297 || param2 == 1019297 ) // ACTOR3 = GYOSAN
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=GYOSAN
            // +Callback Scene00005: Normal(Talk, TargetCanMove), id=GYOSAN
          }
          break;
        }
        if( param1 == 1019303 || param2 == 1019303 ) // ACTOR4 = GYOKU
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=GYOKU
            // +Callback Scene00007: Normal(Talk, TargetCanMove), id=GYOKU
          }
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2009474 || param2 == 2009474 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1019297 || param2 == 1019297 ) // ACTOR3 = GYOSAN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=GYOSAN
          break;
        }
        if( param1 == 1019303 || param2 == 1019303 ) // ACTOR4 = GYOKU
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=GYOKU
          break;
        }
        break;
      }
      case 3:
      {
        Scene00013( player ); // Scene00013: Normal(SystemTalk), id=unknown
        break;
      }
      case 4:
      {
        Scene00015( player ); // Scene00015: Normal(SystemTalk), id=unknown
        break;
      }
      case 255:
      {
        Scene00017( player ); // Scene00017: Normal(SystemTalk), id=unknown
        // +Callback Scene00018: Normal(Talk, FadeIn, AutoFadeIn), id=unknown
        // +Callback Scene00019: Normal(CutScene, FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 2 )
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
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBdd102:68607 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdd102:68607 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, AutoFadeIn), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdd102:68607 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdd102:68607 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdd102:68607 calling Scene00004: Normal(Talk, TargetCanMove), id=GYOSAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdd102:68607 calling Scene00005: Normal(Talk, TargetCanMove), id=GYOSAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdd102:68607 calling Scene00006: Normal(Talk, TargetCanMove), id=GYOKU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdd102:68607 calling Scene00007: Normal(Talk, TargetCanMove), id=GYOKU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdd102:68607 calling Scene00009: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdd102:68607 calling Scene00010: Normal(Talk, TargetCanMove), id=GYOSAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdd102:68607 calling Scene00011: Normal(Talk, TargetCanMove), id=GYOKU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdd102:68607 calling Scene00013: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdd102:68607 calling Scene00015: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBdd102:68607 calling Scene00017: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBdd102:68607 calling Scene00018: Normal(Talk, FadeIn, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00019( player );
    };
    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBdd102:68607 calling Scene00019: Normal(CutScene, FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
          player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
          player.eventFinish( getId(), 1 );
          player.forceZoneing();
        }
      }
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( StmBdd102 );
