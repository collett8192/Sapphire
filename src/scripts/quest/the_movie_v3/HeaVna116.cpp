// FFXIVTheMovie.ParserV3.6
// param used:
//SCENE_4 REMOVED!!
//WARP_SCENE10 = 401|-676.24|-110.8|477.87|0.18|false
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
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HONOROIT
        break;
      }
      case 1:
      {
        if( type != 2 ) Scene00003( player ); // Scene00003: Normal(SystemTalk), id=unknown
        break;
      }
      case 2:
      {
        if( type != 2 ) Scene00005( player ); // Scene00005: Normal(Talk, FadeIn, QuestGimmickReaction, AutoFadeIn), id=unknown
        break;
      }
      case 3:
      {
        if( param1 == 1012366 || param2 == 1012366 ) // ACTOR1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(QuestBattle, YesNo), id=unknown
          }
          break;
        }
        if( param1 == 2005420 || param2 == 2005420 ) // EOBJECT2 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012361 || param2 == 1012361 ) // ACTOR2 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012362 || param2 == 1012362 ) // ACTOR3 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00010( player ); // Scene00010: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012367 || param2 == 1012367 ) // ACTOR4 = CID
        {
          Scene00011( player ); // Scene00011: Normal(Talk, NpcDespawn, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1012368 || param2 == 1012368 ) // ACTOR5 = EMMANELLAIN
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1012369 || param2 == 1012369 ) // ACTOR6 = HAURCHEFANT
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=HAURCHEFANT
          break;
        }
        if( param1 == 1012370 || param2 == 1012370 ) // ACTOR7 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013091 || param2 == 1013091 ) // ACTOR8 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013092 || param2 == 1013092 ) // ACTOR9 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012371 || param2 == 1012371 ) // ACTOR10 = HONOROIT
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=HONOROIT
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
    player.sendDebug( "emote: {}", emoteId );
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
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
  void Scene00001( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00003: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00005: Normal(Talk, FadeIn, QuestGimmickReaction, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_3: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00006: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        //quest battle
        player.eventFinish( getId(), 1 );
        auto& pTeriMgr = Common::Service< Sapphire::World::Manager::TerritoryMgr >::ref();
        pTeriMgr.createAndJoinQuestBattle( player, 104 );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_3: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00007: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00008( Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player ) //SEQ_4: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00010: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 401, -676.24f, -110.8f, 477.87f, 0.18f, false );
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00011: Normal(Talk, NpcDespawn, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=CID" );
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

  void Scene00012( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00012: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00013: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna116:67131 calling Scene00017: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna116 );
