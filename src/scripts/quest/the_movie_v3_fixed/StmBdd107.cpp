// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdd107 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdd107() : Sapphire::ScriptAPI::EventScript( 68612 ){}; 
  ~StmBdd107() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 1 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1025549
  //ACTOR1 = 1025550
  //ACTOR2 = 1025551
  //EOBJECT0 = 2009467
  //LOCACT01 = 5471
  //LOCACTFACE01 = 624
  //LOCBGM01 = 458
  //LOCENPCALISAIE01 = 1019541
  //LOCENPCTHAN01 = 1015842
  //LOCENPCYSHT01 = 1011889
  //LOCEOBJTEASET01 = 2009486
  //LOCEOBJTEASET02 = 2009513
  //LOCLCUTPOSBASE01 = 7379680
  //LOCLCUTPOSTEASET01 = 7379401
  //LOCLEVELTHAN01 = 7344563
  //LOCLEVELYSH01 = 7344562
  //NCUT01 = 1708
  //NCUT02 = 1710
  //QUESTBATTLE0 = 5025
  //TERRITORYTYPE0 = 769
  //TERRITORYTYPE1 = 351

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1025549 || param2 == 1025549 ) // ACTOR0 = ALISAIE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025550 || param2 == 1025550 ) // ACTOR1 = YSHTOLA
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=YSHTOLA
          // +Callback Scene00003: Normal(YesNo, SystemTalk, CanCancel), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2009467 || param2 == 2009467 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, FadeIn, AutoFadeIn), id=unknown
            // +Callback Scene00005: Normal(CutScene, AutoFadeIn), id=unknown
            // +Callback Scene00006: Normal(QuestBattle, YesNo, FadeIn, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1025549 || param2 == 1025549 ) // ACTOR0 = ALISAIE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025550 || param2 == 1025550 ) // ACTOR1 = YSHTOLA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA
          // +Callback Scene00009: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00010( player ); // Scene00010: Normal(Talk, FadeIn, Menu), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1025549 || param2 == 1025549 ) // ACTOR0 = ALISAIE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=ALISAIE
          break;
        }
        if( param1 == 1025550 || param2 == 1025550 ) // ACTOR1 = YSHTOLA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1025551 || param2 == 1025551 ) // ACTOR2 = THANCRED
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=THANCRED
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBdd107:68612 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdd107:68612 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdd107:68612 calling Scene00002: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdd107:68612 calling Scene00003: Normal(YesNo, SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdd107:68612 calling Scene00004: Normal(Talk, FadeIn, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdd107:68612 calling Scene00005: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdd107:68612 calling Scene00006: Normal(QuestBattle, YesNo, FadeIn, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param2 == 1 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
        Scene00010( player );
      }
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdd107:68612 calling Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdd107:68612 calling Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdd107:68612 calling Scene00009: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdd107:68612 calling Scene00010: Normal(Talk, FadeIn, Menu), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdd107:68612 calling Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=ALISAIE" );
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
    player.sendDebug( "StmBdd107:68612 calling Scene00012: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdd107:68612 calling Scene00013: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdd107 );
