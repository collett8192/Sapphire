// FFXIVTheMovie.ParserV3.6
// id hint used:
//PRIVATE_ZANTHAEL = 198
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse216 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse216() : Sapphire::ScriptAPI::EventScript( 66896 ){}; 
  ~GaiUse216() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 7 entries
  //SEQ_2, 6 entries
  //SEQ_3, 6 entries
  //SEQ_255, 6 entries

  //ACTIONTIMELINEEVENTBASEATTENTIONSTAND = 1013
  //ACTIONTIMELINEEVENTBASESORRY = 819
  //ACTOR0 = 1008803
  //ACTOR1 = 1002694
  //ACTOR10 = 1008891
  //ACTOR11 = 1008892
  //ACTOR12 = 1008893
  //ACTOR13 = 1008894
  //ACTOR14 = 1008895
  //ACTOR2 = 1001029
  //ACTOR3 = 1008676
  //ACTOR4 = 1008677
  //ACTOR5 = 1008678
  //ACTOR6 = 1008679
  //ACTOR7 = 1008691
  //ACTOR8 = 1008692
  //ACTOR9 = 1008693
  //CUTSCENEN01 = 469
  //EVENTACTIONSEARCH = 1
  //LEVELIDNPC01 = 4629168
  //LEVELIDNPC02 = 4629169
  //LEVELIDNPC03 = 4629170
  //LEVELIDNPC04 = 4629171
  //LOCACTION10 = 1002
  //LOCACTOR0 = 4087076
  //LOCACTOR1 = 4628783
  //LOCACTOR10 = 4259850
  //LOCACTOR11 = 1008175
  //LOCACTOR2 = 4628784
  //LOCACTOR3 = 4628785
  //LOCACTOR4 = 1008797
  //LOCBGM0 = 88
  //LOCFACE10 = 614
  //LOCFACE11 = 606
  //LOCFACE12 = 617
  //LOCSE1 = 70
  //LOCSE10 = 42
  //POPRANGE0 = 4628787
  //TERRITORYTYPE0 = 198

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=MERLWYB
        break;
      }
      case 1:
      {
        if( param1 == 1002694 || param2 == 1002694 ) // ACTOR1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1001029 || param2 == 1001029 ) // ACTOR2 = ZANTHAEL
        {
          Scene00003( player ); // Scene00003: Normal(Talk, YesNo, TargetCanMove), id=ZANTHAEL
          break;
        }
        if( param1 == 1008676 || param2 == 1008676 ) // ACTOR3 = MINFILIA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1008677 || param2 == 1008677 ) // ACTOR4 = THANCRED
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1008678 || param2 == 1008678 ) // ACTOR5 = YSHTOLA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1008679 || param2 == 1008679 ) // ACTOR6 = YUGIRI
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1008691 || param2 == 1008691 ) // ACTOR7 = EYNZAHRSLAFYRSYN
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=EYNZAHRSLAFYRSYN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1008679 || param2 == 1008679 ) // ACTOR6 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=YUGIRI
          }
          break;
        }
        if( param1 == 1008676 || param2 == 1008676 ) // ACTOR3 = MINFILIA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1008677 || param2 == 1008677 ) // ACTOR4 = THANCRED
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1008678 || param2 == 1008678 ) // ACTOR5 = YSHTOLA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1002694 || param2 == 1002694 ) // ACTOR1 = MERLWYB
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=MERLWYB
          break;
        }
        if( param1 == 1001029 || param2 == 1001029 ) // ACTOR2 = ZANTHAEL
        {
          Scene00014( player ); // Scene00014: Normal(Talk, YesNo, TargetCanMove), id=ZANTHAEL
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1008692 || param2 == 1008692 ) // ACTOR8 = STORMPRIVATE01360
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=STORMPRIVATE01360
          }
          break;
        }
        if( param1 == 1002694 || param2 == 1002694 ) // ACTOR1 = MERLWYB
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=MERLWYB
          break;
        }
        if( param1 == 1008676 || param2 == 1008676 ) // ACTOR3 = MINFILIA
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1008677 || param2 == 1008677 ) // ACTOR4 = THANCRED
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1008678 || param2 == 1008678 ) // ACTOR5 = YSHTOLA
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1008679 || param2 == 1008679 ) // ACTOR6 = YUGIRI
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1008693 || param2 == 1008693 ) // ACTOR9 = EYNZAHRSLAFYRSYN
        {
          Scene00021( player ); // Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=EYNZAHRSLAFYRSYN
          break;
        }
        if( param1 == 1008891 || param2 == 1008891 ) // ACTOR10 = MERLWYB
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=MERLWYB
          break;
        }
        if( param1 == 1008892 || param2 == 1008892 ) // ACTOR11 = MINFILIA
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1008893 || param2 == 1008893 ) // ACTOR12 = THANCRED
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1008894 || param2 == 1008894 ) // ACTOR13 = YSHTOLA
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1008895 || param2 == 1008895 ) // ACTOR14 = YUGIRI
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=YUGIRI
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse216:66896 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00002: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00003: Normal(Talk, YesNo, TargetCanMove), id=ZANTHAEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 198 );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00004: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00005: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00007: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00008: Normal(Talk, TargetCanMove), id=EYNZAHRSLAFYRSYN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: ACTOR6, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00009: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00010: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00011: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00012: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00013: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00014: Normal(Talk, YesNo, TargetCanMove), id=ZANTHAEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 198 );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00015: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=STORMPRIVATE01360" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00016: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00017: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00018: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00019: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00020: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=EYNZAHRSLAFYRSYN" );
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
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00022: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00023: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00024: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00025: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse216:66896 calling Scene00026: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse216 );
