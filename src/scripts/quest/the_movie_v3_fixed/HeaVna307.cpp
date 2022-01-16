// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna307 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna307() : Sapphire::ScriptAPI::EventScript( 67144 ){}; 
  ~HeaVna307() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 3 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1012764
  //ACTOR1 = 1012763
  //ACTOR2 = 1013435
  //ACTOR3 = 1013436
  //ACTOR4 = 1012670
  //ACTOR5 = 1012669
  //CUTSCENEN01 = 807
  //CUTSCENEN02 = 808
  //CUTSCENEN03 = 809
  //CUTSCENEN04 = 810
  //CUTSCENEN05 = 811
  //ENEMY0 = 3988
  //ITEM0 = 2001584
  //LOCACTOR0 = 5864121
  //LOCMUSIC0 = 313
  //POPRANGE0 = 5908344

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012764 || param2 == 1012764 ) // ACTOR0 = ESTINIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=ESTINIEN
          }
          break;
        }
        if( param1 == 1012763 || param2 == 1012763 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1013435 || param2 == 1013435 ) // ACTOR2 = LANCER01607
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=LANCER01607
          break;
        }
        if( param1 == 1013436 || param2 == 1013436 ) // ACTOR3 = ARCHER01607
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ARCHER01607
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 2
      case 1:
      {
        if( param1 == 3988 || param2 == 3988 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 2 )
          {
            player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
            checkProgressSeq1( player );
          }
          break;
        }
        if( param1 == 1013435 || param2 == 1013435 ) // ACTOR2 = LANCER01607
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=LANCER01607
          break;
        }
        if( param1 == 1013436 || param2 == 1013436 ) // ACTOR3 = ARCHER01607
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ARCHER01607
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 2
      case 255:
      {
        if( param1 == 1012670 || param2 == 1012670 ) // ACTOR4 = unknown
        {
          Scene00007( player ); // Scene00007: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00008: Normal(CutScene, AutoFadeIn), id=unknown
          // +Callback Scene00009: Normal(FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1012669 || param2 == 1012669 ) // ACTOR5 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
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
    //player.updateQuest( getId(), 1 );
    player.updateQuest( getId(), 255 );
    player.setQuestUI8BH( getId(), 2 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 2 )
    {
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 2 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna307:67144 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna307:67144 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna307:67144 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna307:67144 calling Scene00003: Normal(Talk, TargetCanMove), id=LANCER01607" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna307:67144 calling Scene00004: Normal(Talk, TargetCanMove), id=ARCHER01607" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }


  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna307:67144 calling Scene00005: Normal(Talk, TargetCanMove), id=LANCER01607" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna307:67144 calling Scene00006: Normal(Talk, TargetCanMove), id=ARCHER01607" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna307:67144 calling Scene00007: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00008( player );
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna307:67144 calling Scene00008: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00009( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna307:67144 calling Scene00009: Normal(FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown" );
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
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna307:67144 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna307 );
