// FFXIVTheMovie.ParserV3.6
// id hint used:
//SCENE_19 = CONJURERC
//SCENE_23 = dummyt
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubFst035 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubFst035() : Sapphire::ScriptAPI::EventScript( 65665 ){}; 
  ~SubFst035() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 6 entries
  //SEQ_3, 2 entries
  //SEQ_4, 1 entries
  //SEQ_5, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000421
  //ACTOR1 = 1000465
  //ACTOR10 = 1000101
  //ACTOR2 = 1000512
  //ACTOR3 = 1000513
  //ACTOR4 = 1000514
  //ACTOR5 = 1000515
  //ACTOR6 = 1000516
  //ACTOR7 = 1000740
  //ACTOR8 = 1000100
  //ACTOR9 = 1000102
  //CUTSCENE02 = 70
  //CUTSCENE03 = 71
  //CUTSCENE04 = 72
  //EOBJECT0 = 2001232
  //EOBJECT10 = 1140471
  //EOBJECT6 = 2654267
  //EOBJECT7 = 2654268
  //EOBJECT8 = 2654272
  //EOBJECT9 = 1140501
  //EVENTACTION = 26
  //EVENTACTIONSEARCH = 1
  //LOCACTOR0 = 1003064
  //LOGMESSAGERECOMMENDLISTUNLOCK = 3701
  //MOTION3 = 708
  //QUESTBATTLE0 = 15
  //REWARD0 = 9
  //REWARDLEVE = 5
  //SEQ0ACTOR0LQ = 50
  //TERRITORYTYPE0 = 225
  //TERRITORYTYPE1 = 148
  //UNLOCKCHECKINNREWARD = 2
  //UNLOCKIMAGEGEARSET = 29
  //UNLOCKIMAGEINN = 18
  //UNLOCKIMAGELEVE = 20

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, TargetCanMove, CanCancel), id=GALFRID
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=GALFRID
        break;
      }
      case 1:
      {
        if( type != 2 ) Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALESTAN
        break;
      }
      case 2:
      {
        if( param1 == 1000512 || param2 == 1000512 ) // ACTOR2 = KIKOKUA
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=KIKOKUA
          }
          break;
        }
        if( param1 == 1000513 || param2 == 1000513 ) // ACTOR3 = KIKOKUB
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=KIKOKUB
          }
          break;
        }
        if( param1 == 1000514 || param2 == 1000514 ) // ACTOR4 = KIKOKUC
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, NpcDespawn, TargetCanMove), id=KIKOKUC
          }
          break;
        }
        if( param1 == 1000515 || param2 == 1000515 ) // ACTOR5 = CONJURERA
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=CONJURERA
          }
          break;
        }
        if( param1 == 1000516 || param2 == 1000516 ) // ACTOR6 = CONJURERB
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=CONJURERB
          }
          break;
        }
        if( param1 == 1000740 || param2 == 1000740 ) // ACTOR7 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1000740 || param2 == 1000740 ) // ACTOR7 = CONJURERC
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=CONJURERC
            // +Callback Scene00019: Normal(QuestBattle, YesNo), id=CONJURERC
          }
          break;
        }
        if( param1 == 2001232 || param2 == 2001232 ) // EOBJECT0 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( type != 2 ) Scene00023( player ); // Scene00023: Normal(CutScene, AutoFadeIn), id=dummyt
        break;
      }
      case 5:
      {
        if( type != 2 ) Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALESTAN
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00025( player ); // Scene00025: Normal(Talk, Message, FadeIn, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=MIOUNNE
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
    if( player.getQuestUI8AL( getId() ) == 5 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.setQuestBitFlag8( getId(), 4, false );
      player.setQuestBitFlag8( getId(), 5, false );
      player.updateQuest( getId(), 3 );
    }
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
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst035:65665 calling Scene00000: Normal(Talk, QuestOffer, TargetCanMove, CanCancel), id=GALFRID" );
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
    player.sendDebug( "SubFst035:65665 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=GALFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst035:65665 calling Scene00002: Normal(Talk, TargetCanMove), id=ALESTAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 5, Flag8(1)=True
  {
    player.sendDebug( "SubFst035:65665 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=KIKOKUA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: ACTOR3, UI8AL = 5, Flag8(2)=True
  {
    player.sendDebug( "SubFst035:65665 calling Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=KIKOKUB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: ACTOR4, UI8AL = 5, Flag8(3)=True
  {
    player.sendDebug( "SubFst035:65665 calling Scene00010: Normal(Talk, NpcDespawn, TargetCanMove), id=KIKOKUC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_2: ACTOR5, UI8AL = 5, Flag8(4)=True
  {
    player.sendDebug( "SubFst035:65665 calling Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=CONJURERA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 4, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_2: ACTOR6, UI8AL = 5, Flag8(5)=True
  {
    player.sendDebug( "SubFst035:65665 calling Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=CONJURERB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 5, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst035:65665 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "SubFst035:65665 calling Scene00018: Normal(Talk, TargetCanMove), id=CONJURERC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00019( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "SubFst035:65665 calling Scene00019: Normal(QuestBattle, YesNo), id=CONJURERC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        //quest battle
        player.eventFinish( getId(), 1 );
        auto& pTeriMgr = Common::Service< Sapphire::World::Manager::TerritoryMgr >::ref();
        pTeriMgr.createAndJoinQuestBattle( player, 15 );
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_3: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst035:65665 calling Scene00021: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00023( Entity::Player& player ) //SEQ_4: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst035:65665 calling Scene00023: Normal(CutScene, AutoFadeIn), id=dummyt" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_5: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst035:65665 calling Scene00024: Normal(Talk, TargetCanMove), id=ALESTAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst035:65665 calling Scene00025: Normal(Talk, Message, FadeIn, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=MIOUNNE" );
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
    player.playScene( getId(), 25, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( SubFst035 );
