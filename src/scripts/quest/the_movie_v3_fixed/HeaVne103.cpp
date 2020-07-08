// FFXIVTheMovie.ParserV3
//fix: black screen
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVne103 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVne103() : Sapphire::ScriptAPI::EventScript( 67879 ){}; 
  ~HeaVne103() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 2 entries
  //SEQ_2, 1 entries
  //SEQ_3, 1 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1017724
  //ACTOR1 = 1017725
  //ACTOR2 = 1017726
  //ACTOR3 = 1012380
  //ACTOR4 = 1016205
  //ACTOR5 = 1016818
  //ACTOR6 = 1006325
  //ACTOR7 = 1017728
  //ACTOR8 = 1017729
  //ACTOR9 = 1007478
  //CUTSCENEN01 = 1257
  //LOCACTION0 = 1041
  //LOCACTION1 = 1071
  //LOCACTOR0 = 1011887
  //LOCACTOR1 = 1017687
  //LOCACTOR2 = 1008180
  //LOCACTOR3 = 6432932
  //LOCACTOR4 = 6432933
  //LOCBGM0 = 77
  //LOCBGM1 = 66
  //LOCFACIAL0 = 607
  //LOCIDLE0 = 4294
  //LOCIDLE1 = 4295
  //LOCSE1 = 95
  //POPRANGE0 = 6432966
  //POPRANGE1 = 6504650
  //POPRANGE2 = 6502169
  //QUEST0 = 65580
  //QUEST1 = 66695
  //QUEST2 = 66849
  //TERRITORYTYPE0 = 212

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1017724 || param2 == 1017724 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017725 || param2 == 1017725 ) // ACTOR1 = CAVALRYA02342
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=CAVALRYA02342
        }
        if( param1 == 1017726 || param2 == 1017726 ) // ACTOR2 = CAVALRYB02342
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=CAVALRYB02342
        }
        break;
      }
      case 1:
      {
        if( param1 == 1012380 || param2 == 1012380 ) // ACTOR3 = AYMERIC
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=AYMERIC
            // +Callback Scene00005: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1016205 || param2 == 1016205 ) // ACTOR4 = ALPHINAUD
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 2:
      {
        Scene00007( player ); // Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00008( player ); // Scene00008: Normal(FadeIn), id=unknown
        }
        break;
      }
      case 255:
      {
        if( param1 == 1006325 || param2 == 1006325 ) // ACTOR6 = BLOEIDIN
        {
          Scene00009( player ); // Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BLOEIDIN
        }
        if( param1 == 1017728 || param2 == 1017728 ) // ACTOR7 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017729 || param2 == 1017729 ) // ACTOR8 = ALISAIE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1007478 || param2 == 1007478 ) // ACTOR9 = URIANGER
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=URIANGER
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
    player.sendDebug( "HeaVne103:67879 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVne103:67879 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVne103:67879 calling Scene00002: Normal(Talk, TargetCanMove), id=CAVALRYA02342" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVne103:67879 calling Scene00003: Normal(Talk, TargetCanMove), id=CAVALRYB02342" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVne103:67879 calling Scene00004: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVne103:67879 calling [BranchTrue]Scene00005: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVne103:67879 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVne103:67879 calling Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVne103:67879 calling Scene00008: Normal(FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVne103:67879 calling Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BLOEIDIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVne103:67879 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVne103:67879 calling Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVne103:67879 calling Scene00012: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVne103 );
