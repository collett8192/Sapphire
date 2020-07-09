// FFXIVTheMovie.ParserV3
//fix: change zone, forgot to add id hint before making manual changes, so change seq 255 scene sequence manully as well
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVng102 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVng102() : Sapphire::ScriptAPI::EventScript( 67893 ){}; 
  ~HeaVng102() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 1 entries
  //SEQ_3, 4 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1012395
  //ACTOR1 = 1012644
  //ACTOR10 = 1018042
  //ACTOR11 = 1018039
  //ACTOR12 = 1018040
  //ACTOR13 = 1012811
  //ACTOR2 = 1018046
  //ACTOR3 = 1018048
  //ACTOR4 = 1000107
  //ACTOR5 = 1013180
  //ACTOR6 = 1018333
  //ACTOR7 = 1015990
  //ACTOR8 = 1017472
  //ACTOR9 = 1018041
  //CUTSCENEN01 = 1307
  //LOCACTOR0 = 1005521
  //LOCACTOR1 = 1011887
  //LOCACTOR2 = 1017687
  //LOCACTOR3 = 1011896
  //LOCACTOR4 = 1012189
  //LOCACTOR5 = 6606383
  //LOCACTOR6 = 6606389
  //LOCACTOR7 = 6606390
  //LOCACTOR8 = 6606391
  //LOCACTOR9 = 6532623
  //LOCARMOR0 = 17491
  //LOCARMOR1 = 17492
  //LOCARMOR2 = 17493
  //LOCARMOR3 = 17494
  //LOCARMOR4 = 10034
  //LOCBGM0 = 86
  //LOCSE0 = 78
  //POPRANGE0 = 6741703
  //POPRANGE1 = 6606377
  //POPRANGE2 = 6562405

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012395 || param2 == 1012395 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1012644 || param2 == 1012644 ) // ACTOR1 = TATARU
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 1:
      {
        if( param1 == 1018046 || param2 == 1018046 ) // ACTOR2 = CID
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=CID
            // +Callback Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=CID
          }
        }
        if( param1 == 1012644 || param2 == 1012644 ) // ACTOR1 = TATARU
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1018048 || param2 == 1018048 ) // ACTOR3 = ALPHINAUD
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 2:
      {
        Scene00007( player ); // Scene00007: Normal(Talk, YesNo, TargetCanMove), id=HIDA
        break;
      }
      case 3:
      {
        if( param1 == 1013180 || param2 == 1013180 ) // ACTOR5 = CID
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=CID
          }
        }
        if( param1 == 1018333 || param2 == 1018333 ) // ACTOR6 = NERO
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=NERO
        }
        if( param1 == 1015990 || param2 == 1015990 ) // ACTOR7 = ALISAIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1017472 || param2 == 1017472 ) // ACTOR8 = YUGIRI
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        break;
      }
      case 255:
      {
        if( param1 == 1018041 || param2 == 1018041 ) // ACTOR9 = unknown
        {
          Scene00012( player );
        }
        if( param1 == 1018042 || param2 == 1018042 ) // ACTOR10 = CID
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=CID
        }
        if( param1 == 1018039 || param2 == 1018039 ) // ACTOR11 = ALISAIE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1018040 || param2 == 1018040 ) // ACTOR12 = YUGIRI
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1012811 || param2 == 1012811 ) // ACTOR13 = TATARU
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=TATARU
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVng102:67893 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVng102:67893 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVng102:67893 calling Scene00002: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVng102:67893 calling Scene00003: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVng102:67893 calling [BranchTrue]Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVng102:67893 calling Scene00005: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVng102:67893 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVng102:67893 calling Scene00007: Normal(Talk, YesNo, TargetCanMove), id=HIDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 != 50 )
      {
        checkProgressSeq2( player );
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 156, 124.1, -15.1, -428.3, -2.81, true );
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVng102:67893 calling Scene00008: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVng102:67893 calling Scene00009: Normal(Talk, TargetCanMove), id=NERO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVng102:67893 calling Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVng102:67893 calling Scene00011: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVng102:67893 calling Scene00012: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVng102:67893 calling Scene00013: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
          player.eventFinish( getId(), 1 );
          player.forceZoneing();
        }
      }
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVng102:67893 calling Scene00014: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVng102:67893 calling Scene00015: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVng102:67893 calling Scene00016: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVng102:67893 calling Scene00017: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVng102 );
