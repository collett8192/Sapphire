// FFXIVTheMovie.ParserV3.6
// param used:
//SCENE_9 = dummyr1
//EVENTRANGE1 = dummyr1
//_EVENTRANGE1 = S
//SCENE_15 = dummyr2
//EVENTRANGE2 = dummyr2
//_EVENTRANGE2 = S
//SCENE_21 = actor7
//SCENE_22 = actor7
//ACTOR7 = actor7
//ACTOR6 = actor6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna327 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna327() : Sapphire::ScriptAPI::EventScript( 67164 ){}; 
  ~HeaVna327() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 6 entries
  //SEQ_2, 6 entries
  //SEQ_3, 6 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1012694
  //ACTOR1 = 1012695
  //ACTOR2 = 1012699
  //ACTOR3 = 1012700
  //ACTOR4 = 1012701
  //ACTOR5 = 1012702
  //ACTOR6 = 1012704
  //ACTOR7 = 1012698
  //ACTOR8 = 1012697
  //CUTSCENEN01 = 828
  //CUTSCENEN02 = 829
  //ENEMY0 = 5885228
  //ENEMY1 = 5885229
  //ENEMY2 = 5885231
  //ENEMY3 = 5885232
  //ENEMY4 = 5885233
  //ENEMY5 = 5885234
  //ENEMY6 = 5937955
  //EOBJECT0 = 2005460
  //EOBJECT1 = 2005461
  //EOBJECT2 = 2005462
  //EVENTRANGE0 = 5859080
  //EVENTRANGE1 = 5859083
  //EVENTRANGE2 = 5859086
  //LOCACTOR0 = 5859101
  //LOCQUEST0 = 66608

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012694 || param2 == 1012694 ) // ACTOR0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(CutScene, QuestAccept), id=unknown
          }
          break;
        }
        if( param1 == 1012695 || param2 == 1012695 ) // ACTOR1 = ESTINIEN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 5859080 || param2 == 5859080 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00003( player ); // Scene00003: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5885228 || param2 == 5885228 ) // ENEMY0 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 5885229 || param2 == 5885229 ) // ENEMY1 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 2005460 || param2 == 2005460 ) // EOBJECT0 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012699 || param2 == 1012699 ) // ACTOR2 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012700 || param2 == 1012700 ) // ACTOR3 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 5859083 || param2 == 5859083 ) // EVENTRANGE1 = dummyr1
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00009( player ); // Scene00009: Normal(Message, PopBNpc), id=dummyr1
          }
          break;
        }
        if( param1 == 5885231 || param2 == 5885231 ) // ENEMY2 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 5885232 || param2 == 5885232 ) // ENEMY3 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 2005461 || param2 == 2005461 ) // EOBJECT1 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012701 || param2 == 1012701 ) // ACTOR4 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012702 || param2 == 1012702 ) // ACTOR5 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 5859086 || param2 == 5859086 ) // EVENTRANGE2 = dummyr2
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00015( player ); // Scene00015: Normal(Message, PopBNpc), id=dummyr2
          }
          break;
        }
        if( param1 == 5885233 || param2 == 5885233 ) // ENEMY4 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 5885234 || param2 == 5885234 ) // ENEMY5 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 5937955 || param2 == 5937955 ) // ENEMY6 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 2005462 || param2 == 2005462 ) // EOBJECT2 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012704 || param2 == 1012704 ) // ACTOR6 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012698 || param2 == 1012698 ) // ACTOR7 = actor7
        {
          Scene00021( player ); // Scene00021: Normal(CutScene, AutoFadeIn), id=actor7
          // +Callback Scene00022: Normal(FadeIn, QuestReward, QuestComplete), id=actor7
          break;
        }
        if( param1 == 1012697 || param2 == 1012697 ) // ACTOR8 = ALPHINAUD
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove, ENpcBind), id=ALPHINAUD
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
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna327:67164 calling Scene00001: Normal(CutScene, QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00002: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: EVENTRANGE0, UI8AL = 2, Flag8(1)=True
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00003: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00004: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00005: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00006: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: EVENTRANGE1, UI8AL = 2, Flag8(1)=True
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00009: Normal(Message, PopBNpc), id=dummyr1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: ENEMY2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: ENEMY3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00013( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player ) //SEQ_3: EVENTRANGE2, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00015: Normal(Message, PopBNpc), id=dummyr2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_3: ENEMY4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00016: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00017( Entity::Player& player ) //SEQ_3: ENEMY5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00017: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00018( Entity::Player& player ) //SEQ_3: ENEMY6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00018: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00019( Entity::Player& player ) //SEQ_3: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00020( Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00021: Normal(CutScene, AutoFadeIn), id=actor7" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00022( player );
    };
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00022( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00022: Normal(FadeIn, QuestReward, QuestComplete), id=actor7" );
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
    player.playScene( getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna327:67164 calling Scene00023: Normal(Talk, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna327 );
