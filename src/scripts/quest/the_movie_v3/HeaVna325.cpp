// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna325 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna325() : Sapphire::ScriptAPI::EventScript( 67162 ){}; 
  ~HeaVna325() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 4 entries
  //SEQ_2, 10 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1013202
  //ACTOR1 = 1012686
  //ACTOR2 = 1012687
  //ACTOR3 = 1012688
  //ACTOR4 = 1012759
  //ACTOR5 = 1012756
  //ACTOR6 = 1012757
  //ACTOR7 = 1012758
  //ACTOR8 = 1012760
  //CUTSCENEN01 = 824
  //CUTSCENEN02 = 996
  //ENEMY0 = 5864462
  //ENEMY1 = 5864463
  //EOBJECT0 = 2005538
  //EOBJECT1 = 2005539
  //EVENTRANGE0 = 5862327
  //EVENTRANGE1 = 5862328
  //LOCACTOR0 = 5858518
  //LOCACTOR1 = 5858519
  //LOCACTOR2 = 5858520
  //LOCACTOR3 = 5862293
  //LOCACTOR4 = 5862296
  //LOCACTOR5 = 5862294

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1013202 || param2 == 1013202 ) // ACTOR0 = MOGHAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MOGHAN
          }
          break;
        }
        if( param1 == 1012686 || param2 == 1012686 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012687 || param2 == 1012687 ) // ACTOR2 = ESTINIEN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012688 || param2 == 1012688 ) // ACTOR3 = ICEHEART
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1012759 || param2 == 1012759 ) // ACTOR4 = MOGHAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove, ENpcBind), id=MOGHAN
          }
          break;
        }
        if( param1 == 1012756 || param2 == 1012756 ) // ACTOR5 = ALPHINAUD
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012757 || param2 == 1012757 ) // ACTOR6 = ESTINIEN
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012758 || param2 == 1012758 ) // ACTOR7 = ICEHEART
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 5862327 || param2 == 5862327 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5864462 || param2 == 5864462 ) // ENEMY0 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 5862328 || param2 == 5862328 ) // EVENTRANGE1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5864463 || param2 == 5864463 ) // ENEMY1 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 2005538 || param2 == 2005538 ) // EOBJECT0 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 2005539 || param2 == 2005539 ) // EOBJECT1 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012757 || param2 == 1012757 ) // ACTOR6 = ESTINIEN
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012758 || param2 == 1012758 ) // ACTOR7 = ICEHEART
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        if( param1 == 1012759 || param2 == 1012759 ) // ACTOR4 = MOGHAN
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=MOGHAN
          break;
        }
        if( param1 == 1012760 || param2 == 1012760 ) // ACTOR8 = ESTINIEN
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012757 || param2 == 1012757 ) // ACTOR6 = ESTINIEN
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ESTINIEN
          // +Callback Scene00020: Normal(CutScene), id=unknown
          // +Callback Scene00021: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1012758 || param2 == 1012758 ) // ACTOR7 = ICEHEART
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        if( param1 == 1012759 || param2 == 1012759 ) // ACTOR4 = MOGHAN
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=MOGHAN
          break;
        }
        if( param1 == 1012760 || param2 == 1012760 ) // ACTOR8 = ESTINIEN
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ESTINIEN
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
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestBitFlag8( getId(), 1, false );
        player.setQuestBitFlag8( getId(), 2, false );
        player.updateQuest( getId(), 255 );
      }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna325:67162 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MOGHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00004: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00005: Normal(Talk, TargetCanMove, ENpcBind), id=MOGHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00007: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00008: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: EVENTRANGE0, UI8BH = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: EVENTRANGE1, UI8AL = 1, Flag8(2)=True
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00013( Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00014( Entity::Player& player ) //SEQ_2: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00014: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00015( Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00015: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00016: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00017: Normal(Talk, TargetCanMove), id=MOGHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00018: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00019: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00020: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00021( player );
    };
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00021( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00021: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
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
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00022: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00023: Normal(Talk, TargetCanMove), id=MOGHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna325:67162 calling Scene00024: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna325 );
