// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse503 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse503() : Sapphire::ScriptAPI::EventScript( 65901 ){}; 
  ~GaiUse503() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 4 entries
  //SEQ_2, 5 entries
  //SEQ_3, 1 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1010849
  //ACTOR1 = 1010848
  //ACTOR10 = 1008969
  //ACTOR2 = 1010850
  //ACTOR3 = 1010851
  //ACTOR4 = 1010852
  //ACTOR5 = 1010853
  //ACTOR6 = 1010891
  //ACTOR7 = 1010855
  //ACTOR8 = 1011122
  //ACTOR9 = 1011123
  //EOBJECT0 = 2005114
  //EOBJECT1 = 2005113
  //EVENTACTIONSEARCHSHORT = 2
  //ITEM0 = 2001498
  //LOCACTOR0 = 5578499
  //LOCACTOR1 = 5578500
  //LOCACTOR2 = 1010404
  //LOCACTOR3 = 1010854
  //LOCACTOR4 = 5578497
  //LOCACTOR5 = 5578845
  //LOCEOBJECT0 = 2005125
  //LOCFACIAL0 = 617
  //LOCMOTION0 = 1002
  //LOCMOTION1 = 708
  //LOCMOTION2 = 707
  //LOCMOTION3 = 1045
  //LOCMOTION4 = 731
  //LOCSE0 = 42
  //LOCSEBOXGET = 78
  //LOCSEBOXSET = 80
  //LOCTALKSHAPE0 = 6

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1010849 || param2 == 1010849 ) // ACTOR0 = ILBERD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ILBERD
          break;
        }
        if( param1 == 1010848 || param2 == 1010848 ) // ACTOR1 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(None), id=unknown
          break;
        }
        if( param1 == 2005114 || param2 == 2005114 ) // EOBJECT0 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( param1 == 2005113 || param2 == 2005113 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2005114 || param2 == 2005114 ) // EOBJECT0 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010849 || param2 == 1010849 ) // ACTOR0 = ILBERD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ILBERD
          break;
        }
        if( param1 == 1010848 || param2 == 1010848 ) // ACTOR1 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( param1 == 1010850 || param2 == 1010850 ) // ACTOR2 = YUYUHASE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: NpcTrade(Talk, TargetCanMove, ENpcBind), id=unknown
            // +Callback Scene00010: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=YUYUHASE
          }
          break;
        }
        if( param1 == 1010851 || param2 == 1010851 ) // ACTOR3 = ALIANNE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALIANNE
          break;
        }
        if( param1 == 1010852 || param2 == 1010852 ) // ACTOR4 = WILRED
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=WILRED
          break;
        }
        if( param1 == 1010848 || param2 == 1010848 ) // ACTOR1 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010849 || param2 == 1010849 ) // ACTOR0 = ILBERD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ILBERD
          break;
        }
        break;
      }
      case 3:
      {
        if( type != 2 ) Scene00015( player ); // Scene00015: Normal(Talk, FadeIn, TargetCanMove), id=RIOL
        break;
      }
      case 255:
      {
        if( param1 == 1010891 || param2 == 1010891 ) // ACTOR6 = TATARU
        {
          Scene00016( player ); // Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1010855 || param2 == 1010855 ) // ACTOR7 = LUCIA
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1011122 || param2 == 1011122 ) // ACTOR8 = MOENBRYDA
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=MOENBRYDA
          break;
        }
        if( param1 == 1011123 || param2 == 1011123 ) // ACTOR9 = URIANGER
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1008969 || param2 == 1008969 ) // ACTOR10 = MINFILIA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=MINFILIA
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
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse503:65901 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00002: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player ) //SEQ_0: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00004: Normal(None), id=unknown" );
    checkProgressSeq0( player );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: EOBJECT1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00005: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00006: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00007: Normal(Talk, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00009: NpcTrade(Talk, TargetCanMove, ENpcBind), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00010( player );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00010: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=YUYUHASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00011: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00012: Normal(Talk, TargetCanMove), id=WILRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00014: Normal(Talk, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_3: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00015: Normal(Talk, FadeIn, TargetCanMove), id=RIOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TATARU" );
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
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00017: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00018: Normal(Talk, TargetCanMove), id=MOENBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00019: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse503:65901 calling Scene00020: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse503 );
