// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdg101 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdg101() : Sapphire::ScriptAPI::EventScript( 68720 ){}; 
  ~StmBdg101() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_255, 4 entries

  //ACTIONTIMELINEEVENTPERCEIVE = 5596
  //ACTIONTIMELINEFACIALSALUTE = 624
  //ACTOR0 = 1026846
  //ACTOR1 = 1026794
  //ACTOR2 = 1026795
  //ACTOR3 = 1026796
  //ACTOR4 = 1026797
  //ACTOR5 = 1026798
  //ACTOR6 = 1026799
  //ACTOR7 = 1026804
  //BGMEVENTSTORMBLOOD03 = 459
  //BGMEVENTTHEMECID = 99
  //BGMEVENTTREMENDOUS01 = 190
  //BINDACTOR0 = 7733713
  //BINDACTOR1 = 7733712
  //BINDACTOR2 = 7733732
  //BINDACTOR3 = 7733733
  //EOBJECT0 = 2009667
  //LCUTACTOR0 = 1026800
  //LCUTACTOR1 = 1026801
  //LCUTACTOR2 = 1011900
  //LCUTACTOR3 = 1026474
  //POPRANGE0 = 7733734
  //SEEVENTDOORCLOSE = 40
  //SEEVENTDOOROPEN = 39

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=HOARYBOULDER
        break;
      }
      case 1:
      {
        if( param1 == 1026794 || param2 == 1026794 ) // ACTOR1 = MAXIMA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MAXIMA
            // +Callback Scene00003: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=MAXIMA
          }
          break;
        }
        if( param1 == 2009667 || param2 == 2009667 ) // EOBJECT0 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1026795 || param2 == 1026795 ) // ACTOR2 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1026796 || param2 == 1026796 ) // ACTOR3 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1026846 || param2 == 1026846 ) // ACTOR0 = HOARYBOULDER
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=HOARYBOULDER
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1026797 || param2 == 1026797 ) // ACTOR4 = CID
        {
          Scene00008( player ); // Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1026798 || param2 == 1026798 ) // ACTOR5 = MAXIMA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=MAXIMA
          break;
        }
        if( param1 == 1026799 || param2 == 1026799 ) // ACTOR6 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 1026804 || param2 == 1026804 ) // ACTOR7 = RESISTANCEGATEKEEPER
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=RESISTANCEGATEKEEPER
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
    player.sendDebug( "StmBdg101:68720 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "StmBdg101:68720 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdg101:68720 calling Scene00002: Normal(Talk, TargetCanMove), id=MAXIMA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdg101:68720 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=MAXIMA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 621, -533, 8.7, -15.8, 1.62, true );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdg101:68720 calling Scene00004: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdg101:68720 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdg101:68720 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdg101:68720 calling Scene00007: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdg101:68720 calling Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CID" );
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
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdg101:68720 calling Scene00009: Normal(Talk, TargetCanMove), id=MAXIMA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdg101:68720 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdg101:68720 calling Scene00011: Normal(Talk, TargetCanMove), id=RESISTANCEGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdg101 );
