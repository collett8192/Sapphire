// FFXIVTheMovie.ParserV3
//fix: skip quest battle
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna116 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna116() : Sapphire::ScriptAPI::EventScript( 67131 ){}; 
  ~HeaVna116() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 4 entries
  //SEQ_4, 1 entries
  //SEQ_255, 7 entries

  //ACTIONTIMELINEEVENTSIGH = 4229
  //ACTIONTIMELINEEVENTSPECIALJOY = 1059
  //ACTIONTIMELINETALKJOKE = 4220
  //ACTOR0 = 1012364
  //ACTOR1 = 1012366
  //ACTOR10 = 1012371
  //ACTOR2 = 1012361
  //ACTOR3 = 1012362
  //ACTOR4 = 1012367
  //ACTOR5 = 1012368
  //ACTOR6 = 1012369
  //ACTOR7 = 1012370
  //ACTOR8 = 1013091
  //ACTOR9 = 1013092
  //CUTSCENEN01 = 794
  //EOBJECT0 = 2005418
  //EOBJECT1 = 2005419
  //EOBJECT2 = 2005420
  //EVENTACTIONLOOKOUTLONG = 41
  //EVENTACTIONLOOKOUTMIDDLE = 50
  //LOCACTOR0 = 1012438
  //LOCEOBJ0 = 2006048
  //LOCPOSACTOR0 = 5903275
  //LOCPOSACTOR1 = 5905503
  //POPRANGE0 = 5905332
  //QUESTBATTLE0 = 104
  //TERRITORYTYPE0 = 455
  //TERRITORYTYPE1 = 401

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HONOROIT
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(None), id=unknown
        break;
      }
      case 2:
      {
        Scene00003( player ); // Scene00003: Normal(None), id=unknown
        break;
      }
      case 3:
      {
        if( actor == 1012366 || actorId == 1012366 ) // ACTOR1 = unknown
        {
          Scene00006( player );
        }
        break;
      }

      case 255:
      {
        if( actor == 1012367 || actorId == 1012367 ) // ACTOR4 = CID
        {
          Scene00011( player );
        }
        if( actor == 1012368 || actorId == 1012368 ) // ACTOR5 = EMMANELLAIN
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        if( actor == 1012369 || actorId == 1012369 ) // ACTOR6 = HAURCHEFANT
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=HAURCHEFANT
        }
        if( actor == 1012370 || actorId == 1012370 ) // ACTOR7 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        if( actor == 1013091 || actorId == 1013091 ) // ACTOR8 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( actor == 1013092 || actorId == 1013092 ) // ACTOR9 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        if( actor == 1012371 || actorId == 1012371 ) // ACTOR10 = HONOROIT
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=HONOROIT
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
    onProgress( player, param1, param1, 3, param1 );
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna116:67131 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00002: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00003: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00004: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00005: Normal(FadeIn, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00006: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00010( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00008: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna116:67131 calling [BranchTrue]Scene00010: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 401, -726.8, -105, 470, 1 );
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna116:67131 calling [BranchChain]Scene00011: Normal(Talk, NpcDespawn, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00012: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00013: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00017: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna116 );
