// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse602 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse602() : Sapphire::ScriptAPI::EventScript( 65907 ){}; 
  ~GaiUse602() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_2, 7 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1010930
  //ACTOR1 = 1010931
  //ACTOR2 = 1006384
  //ACTOR3 = 1006401
  //ACTOR4 = 1010939
  //ACTOR5 = 1010940
  //ACTOR6 = 1010941
  //ACTOR7 = 1010942
  //ACTOR8 = 1010951
  //CUTSCENEN01 = 706
  //LOCACTOR0 = 1008193
  //LOCACTOR1 = 5579058
  //LOCPOSACTOR0 = 5655830
  //LOCSE0 = 44

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD
        // +Callback Scene00002: Normal(CutScene, AutoFadeIn), id=unknown
        break;
      }
      case 1:
      {
        if( param1 == 1010931 || param2 == 1010931 ) // ACTOR1 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1006384 || param2 == 1006384 ) // ACTOR2 = HAURCHEFANT
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=HAURCHEFANT
          break;
        }
        if( param1 == 1006401 || param2 == 1006401 ) // ACTOR3 = YAELLE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YAELLE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1010939 || param2 == 1010939 ) // ACTOR4 = TEMPLERA00371
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=TEMPLERA00371
          }
          break;
        }
        if( param1 == 1010940 || param2 == 1010940 ) // ACTOR5 = TEMPLERB00371
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=TEMPLERB00371
          }
          break;
        }
        if( param1 == 1010941 || param2 == 1010941 ) // ACTOR6 = CAVALRYMANB00371
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=CAVALRYMANB00371
          }
          break;
        }
        if( param1 == 1010942 || param2 == 1010942 ) // ACTOR7 = CAVALRYMANA00371
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=CAVALRYMANA00371
          }
          break;
        }
        if( param1 == 1010951 || param2 == 1010951 ) // ACTOR8 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1006384 || param2 == 1006384 ) // ACTOR2 = HAURCHEFANT
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=HAURCHEFANT
          break;
        }
        if( param1 == 1006401 || param2 == 1006401 ) // ACTOR3 = YAELLE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YAELLE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1010951 || param2 == 1010951 ) // ACTOR8 = ALPHINAUD
        {
          Scene00013( player ); // Scene00013: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1006384 || param2 == 1006384 ) // ACTOR2 = HAURCHEFANT
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=HAURCHEFANT
          break;
        }
        if( param1 == 1006401 || param2 == 1006401 ) // ACTOR3 = YAELLE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=YAELLE
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 4 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.setQuestBitFlag8( getId(), 4, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse602:65907 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse602:65907 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00002( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse602:65907 calling Scene00002: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse602:65907 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse602:65907 calling Scene00004: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse602:65907 calling Scene00005: Normal(Talk, TargetCanMove), id=YAELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: ACTOR4, UI8AL = 4, Flag8(1)=True
  {
    player.sendDebug( "GaiUse602:65907 calling Scene00006: Normal(Talk, TargetCanMove), id=TEMPLERA00371" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: ACTOR5, UI8AL = 4, Flag8(2)=True
  {
    player.sendDebug( "GaiUse602:65907 calling Scene00007: Normal(Talk, TargetCanMove), id=TEMPLERB00371" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR6, UI8AL = 4, Flag8(3)=True
  {
    player.sendDebug( "GaiUse602:65907 calling Scene00008: Normal(Talk, TargetCanMove), id=CAVALRYMANB00371" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: ACTOR7, UI8AL = 4, Flag8(4)=True
  {
    player.sendDebug( "GaiUse602:65907 calling Scene00009: Normal(Talk, TargetCanMove), id=CAVALRYMANA00371" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 4, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse602:65907 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse602:65907 calling Scene00011: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse602:65907 calling Scene00012: Normal(Talk, TargetCanMove), id=YAELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse602:65907 calling Scene00013: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse602:65907 calling Scene00014: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse602:65907 calling Scene00015: Normal(Talk, TargetCanMove), id=YAELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse602 );
