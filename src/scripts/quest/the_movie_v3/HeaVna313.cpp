// FFXIVTheMovie.ParserV3.6
// param used:
//_ACTOR3 = B
//_ACTOR3B = 1|2
//_ACTOR4 = B
//_ACTOR4B = 1|2
//_ACTOR5 = B
//_ACTOR5B = 1|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna313 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna313() : Sapphire::ScriptAPI::EventScript( 67150 ){}; 
  ~HeaVna313() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 6 entries
  //SEQ_2, 7 entries
  //SEQ_3, 8 entries
  //SEQ_4, 7 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1012636
  //ACTOR1 = 1012637
  //ACTOR10 = 1013582
  //ACTOR11 = 1013583
  //ACTOR12 = 1012672
  //ACTOR2 = 1012632
  //ACTOR3 = 1011928
  //ACTOR4 = 1011929
  //ACTOR5 = 1011930
  //ACTOR6 = 1014195
  //ACTOR7 = 1014196
  //ACTOR8 = 1014197
  //ACTOR9 = 1011931
  //ENEMY0 = 4467
  //ITEM0 = 2001579
  //LOCACTOR0 = 5856619
  //LOCACTOR1 = 5856622
  //LOCACTOR10 = 5887780
  //LOCACTOR11 = 5887793
  //LOCACTOR20 = 5802668
  //LOCACTOR21 = 5871823

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012636 || param2 == 1012636 ) // ACTOR0 = ICEHEART
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=ICEHEART
          }
          break;
        }
        if( param1 == 1012637 || param2 == 1012637 ) // ACTOR1 = ESTINIEN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012632 || param2 == 1012632 ) // ACTOR2 = ALPHINAUD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1011928 || param2 == 1011928 ) // ACTOR3 = STORYTELLER, CB=2
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=STORYTELLER
          }
          else
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=STORYTELLER
          }
          break;
        }
        if( param1 == 1011929 || param2 == 1011929 ) // ACTOR4 = IDATEN, CB=2
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=IDATEN
          }
          else
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=IDATEN
          }
          break;
        }
        if( param1 == 1011930 || param2 == 1011930 ) // ACTOR5 = CIBLEROIT, CB=2
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=CIBLEROIT
          }
          else
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=CIBLEROIT
          }
          break;
        }
        if( param1 == 1014195 || param2 == 1014195 ) // ACTOR6 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1014196 || param2 == 1014196 ) // ACTOR7 = ESTINIEN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1014197 || param2 == 1014197 ) // ACTOR8 = ICEHEART
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1011931 || param2 == 1011931 ) // ACTOR9 = NANKAEATER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=NANKAEATER
          }
          break;
        }
        if( param1 == 1011928 || param2 == 1011928 ) // ACTOR3 = STORYTELLER
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=STORYTELLER
          break;
        }
        if( param1 == 1011929 || param2 == 1011929 ) // ACTOR4 = IDATEN
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=IDATEN
          break;
        }
        if( param1 == 1011930 || param2 == 1011930 ) // ACTOR5 = CIBLEROIT
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=CIBLEROIT
          break;
        }
        if( param1 == 1014195 || param2 == 1014195 ) // ACTOR6 = ALPHINAUD
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1014196 || param2 == 1014196 ) // ACTOR7 = ESTINIEN
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1014197 || param2 == 1014197 ) // ACTOR8 = ICEHEART
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( param1 == 4467 || param2 == 4467 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            player.setQuestUI8BH( getId(), 1 );
            checkProgressSeq3( player );
          }
          break;
        }
        if( param1 == 1011928 || param2 == 1011928 ) // ACTOR3 = STORYTELLER
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=STORYTELLER
          break;
        }
        if( param1 == 1011929 || param2 == 1011929 ) // ACTOR4 = IDATEN
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=IDATEN
          break;
        }
        if( param1 == 1011930 || param2 == 1011930 ) // ACTOR5 = CIBLEROIT
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=CIBLEROIT
          break;
        }
        if( param1 == 1014195 || param2 == 1014195 ) // ACTOR6 = ALPHINAUD
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1014196 || param2 == 1014196 ) // ACTOR7 = ESTINIEN
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1014197 || param2 == 1014197 ) // ACTOR8 = ICEHEART
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        if( param1 == 1011931 || param2 == 1011931 ) // ACTOR9 = NANKAEATER
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=NANKAEATER
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( param1 == 1011931 || param2 == 1011931 ) // ACTOR9 = NANKAEATER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00028: Normal(Talk, TargetCanMove), id=NANKAEATER
          }
          break;
        }
        if( param1 == 1013582 || param2 == 1013582 ) // ACTOR10 = ALPHINAUD
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1013583 || param2 == 1013583 ) // ACTOR11 = ESTINIEN
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012672 || param2 == 1012672 ) // ACTOR12 = ICEHEART
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        if( param1 == 1011928 || param2 == 1011928 ) // ACTOR3 = STORYTELLER
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=STORYTELLER
          break;
        }
        if( param1 == 1011929 || param2 == 1011929 ) // ACTOR4 = IDATEN
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=IDATEN
          break;
        }
        if( param1 == 1011930 || param2 == 1011930 ) // ACTOR5 = CIBLEROIT
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=CIBLEROIT
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1013582 || param2 == 1013582 ) // ACTOR10 = ALPHINAUD
        {
          Scene00035( player ); // Scene00035: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=ALPHINAUD
          break;
        }
        if( param1 == 1013583 || param2 == 1013583 ) // ACTOR11 = ESTINIEN
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012672 || param2 == 1012672 ) // ACTOR12 = ICEHEART
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        if( param1 == 1011931 || param2 == 1011931 ) // ACTOR9 = NANKAEATER
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=NANKAEATER
          break;
        }
        if( param1 == 1011928 || param2 == 1011928 ) // ACTOR3 = STORYTELLER
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=STORYTELLER
          break;
        }
        if( param1 == 1011929 || param2 == 1011929 ) // ACTOR4 = IDATEN
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=IDATEN
          break;
        }
        if( param1 == 1011930 || param2 == 1011930 ) // ACTOR5 = CIBLEROIT
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=CIBLEROIT
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
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
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
    if( player.getQuestUI8BH( getId() ) == 1 )
    {
      player.updateQuest( getId(), 4 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna313:67150 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00002: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 3, Flag8(1)=True, Branch
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00004: Normal(Talk, TargetCanMove), id=STORYTELLER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 3, Flag8(1)=True, Branch
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00005: Normal(Talk, TargetCanMove), id=STORYTELLER" );
    player.playScene( getId(), 5, NONE, nullptr );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 3, Flag8(2)=True, Branch
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00006: Normal(Talk, TargetCanMove), id=IDATEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 3, Flag8(2)=True, Branch
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00007: Normal(Talk, TargetCanMove), id=IDATEN" );
    player.playScene( getId(), 7, NONE, nullptr );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 3, Flag8(3)=True, Branch
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00008: Normal(Talk, TargetCanMove), id=CIBLEROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 3, Flag8(3)=True, Branch
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00009: Normal(Talk, TargetCanMove), id=CIBLEROIT" );
    player.playScene( getId(), 9, NONE, nullptr );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00011: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00012: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_2: ACTOR9, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00013: Normal(Talk, TargetCanMove), id=NANKAEATER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00014: Normal(Talk, TargetCanMove), id=STORYTELLER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00015: Normal(Talk, TargetCanMove), id=IDATEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00016: Normal(Talk, TargetCanMove), id=CIBLEROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00018: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00019: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }


  void Scene00020( Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00020: Normal(Talk, TargetCanMove), id=STORYTELLER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00021: Normal(Talk, TargetCanMove), id=IDATEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00022: Normal(Talk, TargetCanMove), id=CIBLEROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00024: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00025: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00026: Normal(Talk, TargetCanMove), id=NANKAEATER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player ) //SEQ_4: ACTOR9, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00027: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00028( player );
      }
    };
    player.playScene( getId(), 27, NONE, callback );
  }
  void Scene00028( Entity::Player& player ) //SEQ_4: ACTOR9, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00028: Normal(Talk, TargetCanMove), id=NANKAEATER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player ) //SEQ_4: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00029: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player ) //SEQ_4: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00030: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player ) //SEQ_4: ACTOR12, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00031: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00032: Normal(Talk, TargetCanMove), id=STORYTELLER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player ) //SEQ_4: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00033: Normal(Talk, TargetCanMove), id=IDATEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00034: Normal(Talk, TargetCanMove), id=CIBLEROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00035: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=ALPHINAUD" );
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
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00036: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00037: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00038: Normal(Talk, TargetCanMove), id=NANKAEATER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00039: Normal(Talk, TargetCanMove), id=STORYTELLER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00040: Normal(Talk, TargetCanMove), id=IDATEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna313:67150 calling Scene00041: Normal(Talk, TargetCanMove), id=CIBLEROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna313 );
