// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil159 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil159() : Sapphire::ScriptAPI::EventScript( 66963 ){}; 
  ~SubWil159() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_2, 4 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1007799
  //ACTOR1 = 1007800
  //ACTOR2 = 1001697
  //ACTOR3 = 1007801
  //ACTOR4 = 1007798
  //EVENTACTIONSEARCH = 1
  //LOCACTION0 = 573
  //LOCACTION1 = 574
  //LOCACTOR0 = 1007993
  //LOCBGM1 = 88
  //LOCBGM2 = 82
  //LOCFACE0 = 605
  //LOCFACE1 = 612
  //LOCFACE2 = 615
  //LOCFACE3 = 606
  //LOCPOSACTOR0 = 4672004
  //LOCPOSACTOR1 = 4672622
  //LOCPOSACTOR2 = 4672825

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=PMOLMINN
        // +Callback Scene00001: Normal(QuestAccept), id=unknown
        break;
      }
      case 1:
      {
        if( param1 == 1007800 || param2 == 1007800 ) // ACTOR1 = WOMENA01427
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=WOMENA01427
            // +Callback Scene00003: Normal(Talk, TargetCanMove), id=WOMENA01427
          }
          break;
        }
        if( param1 == 1001697 || param2 == 1001697 ) // ACTOR2 = SOSOTTA
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=SOSOTTA
            // +Callback Scene00005: Normal(Talk, TargetCanMove), id=SOSOTTA
          }
          break;
        }
        if( param1 == 1007801 || param2 == 1007801 ) // ACTOR3 = WOMENB01427
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=WOMENB01427
            // +Callback Scene00007: Normal(Talk, TargetCanMove), id=WOMENB01427
          }
          break;
        }
        if( param1 == 1007799 || param2 == 1007799 ) // ACTOR0 = PMOLMINN
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=PMOLMINN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1007798 || param2 == 1007798 ) // ACTOR4 = GUILLAUNAUX
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=GUILLAUNAUX
          }
          break;
        }
        if( param1 == 1007799 || param2 == 1007799 ) // ACTOR0 = PMOLMINN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=PMOLMINN
          break;
        }
        if( param1 == 1007800 || param2 == 1007800 ) // ACTOR1 = WOMENA01427
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=WOMENA01427
          break;
        }
        if( param1 == 1007801 || param2 == 1007801 ) // ACTOR3 = WOMENB01427
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=WOMENB01427
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1007798 || param2 == 1007798 ) // ACTOR4 = GUILLAUNAUX
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=GUILLAUNAUX
          // +Callback Scene00014: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=GUILLAUNAUX
          // +Callback Scene00015: Normal(Talk, TargetCanMove), id=GUILLAUNAUX
          break;
        }
        if( param1 == 1007799 || param2 == 1007799 ) // ACTOR0 = PMOLMINN
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=PMOLMINN
          break;
        }
        if( param1 == 1007800 || param2 == 1007800 ) // ACTOR1 = WOMENA01427
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=WOMENA01427
          break;
        }
        if( param1 == 1007801 || param2 == 1007801 ) // ACTOR3 = WOMENB01427
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=WOMENB01427
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil159:66963 calling Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=PMOLMINN" );
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
    player.sendDebug( "SubWil159:66963 calling Scene00001: Normal(QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "SubWil159:66963 calling Scene00002: Normal(Talk, TargetCanMove), id=WOMENA01427" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "SubWil159:66963 calling Scene00003: Normal(Talk, TargetCanMove), id=WOMENA01427" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 3, Flag8(2)=True
  {
    player.sendDebug( "SubWil159:66963 calling Scene00004: Normal(Talk, TargetCanMove), id=SOSOTTA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 3, Flag8(2)=True
  {
    player.sendDebug( "SubWil159:66963 calling Scene00005: Normal(Talk, TargetCanMove), id=SOSOTTA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 3, Flag8(3)=True
  {
    player.sendDebug( "SubWil159:66963 calling Scene00006: Normal(Talk, TargetCanMove), id=WOMENB01427" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 3, Flag8(3)=True
  {
    player.sendDebug( "SubWil159:66963 calling Scene00007: Normal(Talk, TargetCanMove), id=WOMENB01427" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil159:66963 calling Scene00008: Normal(Talk, TargetCanMove), id=PMOLMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: ACTOR4, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "SubWil159:66963 calling Scene00009: Normal(Talk, TargetCanMove), id=GUILLAUNAUX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil159:66963 calling Scene00010: Normal(Talk, TargetCanMove), id=PMOLMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil159:66963 calling Scene00011: Normal(Talk, TargetCanMove), id=WOMENA01427" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil159:66963 calling Scene00012: Normal(Talk, TargetCanMove), id=WOMENB01427" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil159:66963 calling Scene00013: Normal(Talk, TargetCanMove), id=GUILLAUNAUX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil159:66963 calling Scene00014: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=GUILLAUNAUX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00015( player );
      }
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00015( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil159:66963 calling Scene00015: Normal(Talk, TargetCanMove), id=GUILLAUNAUX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil159:66963 calling Scene00016: Normal(Talk, TargetCanMove), id=PMOLMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil159:66963 calling Scene00017: Normal(Talk, TargetCanMove), id=WOMENA01427" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil159:66963 calling Scene00018: Normal(Talk, TargetCanMove), id=WOMENB01427" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil159 );
