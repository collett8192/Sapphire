// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKme113 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKme113() : Sapphire::ScriptAPI::EventScript( 69178 ){}; 
  ~LucKme113() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 2 entries
  //SEQ_2, 5 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1030253
  //ACTOR1 = 1030254
  //ACTOR2 = 1030293
  //ACTOR3 = 1030291
  //ACTOR4 = 1030294
  //ACTOR5 = 1030295
  //ACTOR6 = 1030296
  //CUTSCENE0 = 2047
  //CUTSCENE1 = 2048
  //EOBJECT0 = 2010714
  //EVENTACTION0 = 35
  //EVENTACTION1 = 41
  //POPRANGE0 = 7949562

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1030253 || param2 == 1030253 ) // ACTOR0 = CHAINUZZ
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1030254 || param2 == 1030254 ) // ACTOR1 = DULIACHAI
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1030254 || param2 == 1030254 ) // ACTOR1 = DULIACHAI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=DULIACHAI
          }
          break;
        }
        if( param1 == 1030253 || param2 == 1030253 ) // ACTOR0 = CHAINUZZ
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1030293 || param2 == 1030293 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1030254 || param2 == 1030254 ) // ACTOR1 = DULIACHAI
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1030253 || param2 == 1030253 ) // ACTOR0 = CHAINUZZ
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1030291 || param2 == 1030291 ) // ACTOR3 = BALAENICEPSREX
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove, SystemTalk), id=BALAENICEPSREX
          break;
        }
        if( param1 == 2010714 || param2 == 2010714 ) // EOBJECT0 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(SystemTalk), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030294 || param2 == 1030294 ) // ACTOR4 = MYSTERYVOICE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MYSTERYVOICE
          // +Callback Scene00013: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1030295 || param2 == 1030295 ) // ACTOR5 = CHAINUZZ
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1030296 || param2 == 1030296 ) // ACTOR6 = DULIACHAI
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=DULIACHAI
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKme113:69178 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "LucKme113:69178 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKme113:69178 calling Scene00002: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKme113:69178 calling Scene00003: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKme113:69178 calling Scene00004: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKme113:69178 calling Scene00006: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKme113:69178 calling Scene00007: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKme113:69178 calling Scene00008: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKme113:69178 calling Scene00009: Normal(Talk, TargetCanMove, SystemTalk), id=BALAENICEPSREX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKme113:69178 calling Scene00011: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKme113:69178 calling Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00013( player );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKme113:69178 calling Scene00013: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKme113:69178 calling Scene00014: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKme113:69178 calling Scene00015: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKme113 );
