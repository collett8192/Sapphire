// FFXIVTheMovie.ParserV3.1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda325 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda325() : Sapphire::ScriptAPI::EventScript( 68470 ){}; 
  ~StmBda325() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 2 entries
  //SEQ_2, 5 entries
  //SEQ_255, 5 entries

  //ACTIONTIMELINEEVENTTALK1SIT = 5464
  //ACTIONTIMELINEEVENTTALK2SIT = 5465
  //ACTOR0 = 1020004
  //ACTOR1 = 1020007
  //ACTOR2 = 1020008
  //ACTOR3 = 1020011
  //ACTOR4 = 1020017
  //ACTOR5 = 1020009
  //ACTOR6 = 1020010
  //BINDACTOR0 = 6925469
  //CUTSCENEN01 = 1425
  //EVENTPICTRUEMAINQUEST4002 = 532
  //EVENTPICTRUEMAINQUEST4003 = 533
  //LOCBGM0 = 458
  //POPRANGE0 = 6790667
  //TERRITORYTYPE0 = 681

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020004 || param2 == 1020004 ) // ACTOR0 = RESSIANGATEKEEPER
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
                                // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=RESSIANGATEKEEPER
        }
        if( param1 == 1020007 || param2 == 1020007 ) // ACTOR1 = GOSETSU
        {
          Scene00002( player ); // Scene00002: Normal(Talk), id=GOSETSU
        }
        break;
      }
      case 1:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00003( player ); // Scene00003: Normal(CutScene), id=unknown
        }
        if( param1 == 1020004 || param2 == 1020004 ) // ACTOR0 = RESSIANGATEKEEPER
        {
          Scene00004( player ); // Scene00004: Normal(Talk, YesNo, TargetCanMove), id=RESSIANGATEKEEPER
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020008 || param2 == 1020008 ) // ACTOR2 = ALISAIE
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE
                                  // +Callback Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE
          }
        }
        if( param1 == 1020011 || param2 == 1020011 ) // ACTOR3 = YUGIRI
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1020017 || param2 == 1020017 ) // ACTOR4 = RESISTANCE02492
        {
          Scene00008( player ); // Scene00008: Normal(Talk), id=RESISTANCE02492
        }
        if( param1 == 1020009 || param2 == 1020009 ) // ACTOR5 = GOSETSU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=GOSETSU
                                  // +Callback Scene00010: Normal(Talk, TargetCanMove), id=GOSETSU
          }
        }
        if( param1 == 1020010 || param2 == 1020010 ) // ACTOR6 = LYSE
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=LYSE
                                  // +Callback Scene00012: Normal(Talk, TargetCanMove), id=LYSE
          }
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020011 || param2 == 1020011 ) // ACTOR3 = YUGIRI
        {
          Scene00013( player ); // Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, Menu), id=YUGIRI
        }
        if( param1 == 1020008 || param2 == 1020008 ) // ACTOR2 = ALISAIE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020009 || param2 == 1020009 ) // ACTOR5 = GOSETSU
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1020010 || param2 == 1020010 ) // ACTOR6 = LYSE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020017 || param2 == 1020017 ) // ACTOR4 = RESISTANCE02492
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=RESISTANCE02492
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
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda325:68470 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda325:68470 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=RESSIANGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.enterPredefinedPrivateInstance( 681 );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda325:68470 calling Scene00002: Normal(Talk), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda325:68470 calling Scene00003: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda325:68470 calling Scene00004: Normal(Talk, YesNo, TargetCanMove), id=RESSIANGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 681 );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda325:68470 calling Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda325:68470 calling [BranchTrue]Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda325:68470 calling Scene00007: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda325:68470 calling Scene00008: Normal(Talk), id=RESISTANCE02492" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda325:68470 calling Scene00009: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda325:68470 calling [BranchTrue]Scene00010: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda325:68470 calling Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda325:68470 calling [BranchTrue]Scene00012: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda325:68470 calling Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, Menu), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda325:68470 calling Scene00014: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda325:68470 calling Scene00015: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda325:68470 calling Scene00016: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda325:68470 calling Scene00017: Normal(Talk, TargetCanMove), id=RESISTANCE02492" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda325 );
