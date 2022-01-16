// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna324 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna324() : Sapphire::ScriptAPI::EventScript( 67161 ){}; 
  ~HeaVna324() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 6 entries
  //SEQ_2, 6 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1012682
  //ACTOR1 = 1012683
  //ACTOR10 = 1012688
  //ACTOR2 = 1012680
  //ACTOR3 = 1012684
  //ACTOR4 = 1012689
  //ACTOR5 = 1012690
  //ACTOR6 = 1012691
  //ACTOR7 = 1013202
  //ACTOR8 = 1012686
  //ACTOR9 = 1012687
  //ENEMY0 = 5864455
  //ENEMY1 = 5864456
  //ENEMY2 = 5864459
  //ENEMY3 = 5864460
  //ENEMY4 = 5864461
  //EOBJECT0 = 2005457
  //EOBJECT1 = 2005458
  //EVENTRANGE0 = 5858517
  //EVENTRANGE1 = 5858515
  //LOCACTOR0 = 5858507
  //LOCACTOR1 = 5858495
  //LOCACTOR2 = 5858508

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012682 || param2 == 1012682 ) // ACTOR0 = MOGHAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MOGHAN
          }
          break;
        }
        if( param1 == 1012683 || param2 == 1012683 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012680 || param2 == 1012680 ) // ACTOR2 = ESTINIEN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012684 || param2 == 1012684 ) // ACTOR3 = ICEHEART
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 5858517 || param2 == 5858517 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00005( player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5864455 || param2 == 5864455 ) // ENEMY0 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 5864456 || param2 == 5864456 ) // ENEMY1 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012689 || param2 == 1012689 ) // ACTOR4 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012690 || param2 == 1012690 ) // ACTOR5 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 2005457 || param2 == 2005457 ) // EOBJECT0 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 5858515 || param2 == 5858515 ) // EVENTRANGE1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00011( player ); // Scene00011: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5864459 || param2 == 5864459 ) // ENEMY2 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 5864460 || param2 == 5864460 ) // ENEMY3 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 5864461 || param2 == 5864461 ) // ENEMY4 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012691 || param2 == 1012691 ) // ACTOR6 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 2005458 || param2 == 2005458 ) // EOBJECT1 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1013202 || param2 == 1013202 ) // ACTOR7 = MOGHAN
        {
          Scene00017( player ); // Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MOGHAN
          break;
        }
        if( param1 == 1012686 || param2 == 1012686 ) // ACTOR8 = ALPHINAUD
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012687 || param2 == 1012687 ) // ACTOR9 = ESTINIEN
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012688 || param2 == 1012688 ) // ACTOR10 = ICEHEART
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ICEHEART
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
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna324:67161 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MOGHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00004: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: EVENTRANGE0, UI8AL = 2, Flag8(1)=True
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00006: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00007: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: EVENTRANGE1, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: ENEMY2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00013( Entity::Player& player ) //SEQ_2: ENEMY3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00014( Entity::Player& player ) //SEQ_2: ENEMY4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00014: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00015( Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player ) //SEQ_2: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00016: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00017( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MOGHAN" );
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
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00018: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00019: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna324:67161 calling Scene00020: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna324 );
