// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea923 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea923() : Sapphire::ScriptAPI::EventScript( 65782 ){}; 
  ~SubSea923() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 4 entries
  //SEQ_4, 5 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1000856
  //ACTOR1 = 1003585
  //ACTOR2 = 1000857
  //ACTOR3 = 1008882
  //ACTOR4 = 1005414
  //LCUTACTORASCELYN01 = 1008946
  //LCUTACTORCHEER01 = 4165351
  //LCUTACTORFISHERMAN01 = 1010698
  //LCUTACTORFISHER01 = 5049369
  //LCUTACTORNEPTDRAGON01 = 1010699
  //LCUTACTORSISIPU = 1673578
  //LCUTACTORWAWARAGO = 1673577
  //LCUTBGMDISQUIET01 = 78
  //LCUTBGMJOY01 = 87
  //LCUTBGMRISEINARMS01 = 86
  //LCUTBGMTHEMEFACEWAR01 = 83
  //LCUTBGMTHEMEREST0201 = 98
  //LCUTMOTIONBASELIE01 = 981
  //LCUTMOTIONEVENTARMS = 1041
  //LCUTPOSASCELYN01 = 4632830
  //LCUTPOSPC01 = 4653199
  //POPRANGE0 = 4165755
  //RITEM0 = 8756
  //RITEM1 = 8775
  //RITEM2 = 8768
  //RITEM3 = 8772
  //RITEM4 = 8763
  //RITEM5 = 8754

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=WAWALAGO
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=WAWALAGO
        break;
      }
      case 2:
      {
        Scene00004( player ); // Scene00004: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=WAWALAGO
        break;
      }
      case 3:
      {
        if( actor == 1003585 || actorId == 1003585 ) // ACTOR1 = STEERSMAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=STEERSMAN
          }
        }
        if( actor == 1000857 || actorId == 1000857 ) // ACTOR2 = SISIPU
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=SISIPU
        }
        if( actor == 1000856 || actorId == 1000856 ) // ACTOR0 = WAWALAGO
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=WAWALAGO
        }
        if( actor == 1008882 || actorId == 1008882 ) // ACTOR3 = ASCELYN
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ASCELYN
        }
        break;
      }
      case 4:
      {
        if( actor == 1005414 || actorId == 1005414 ) // ACTOR4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=unknown
          }
        }
        if( actor == 1003585 || actorId == 1003585 ) // ACTOR1 = STEERSMAN
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=STEERSMAN
        }
        if( actor == 1000857 || actorId == 1000857 ) // ACTOR2 = SISIPU
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=SISIPU
        }
        if( actor == 1000856 || actorId == 1000856 ) // ACTOR0 = WAWALAGO
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=WAWALAGO
        }
        if( actor == 1008882 || actorId == 1008882 ) // ACTOR3 = ASCELYN
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ASCELYN
        }
        break;
      }
      case 255:
      {
        if( actor == 1000856 || actorId == 1000856 ) // ACTOR0 = WAWALAGO
        {
          Scene00016( player ); // Scene00016: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=WAWALAGO
        }
        if( actor == 1000857 || actorId == 1000857 ) // ACTOR2 = SISIPU
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=SISIPU
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
    onProgress( player, actorId, actor, 1, emoteId );
  }

  void onBNpcKill( uint32_t npcId, Entity::Player& player ) override
  {
    onProgress( player, npcId, 0, 2, 0 );
  }

  void onWithinRange( Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z ) override
  {
    onProgress( player, param1, param1, 3, param1 );
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubSea923:65782 calling Scene00000: Normal(QuestOffer), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "SubSea923:65782 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=WAWALAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubSea923:65782 calling Scene00002: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00003( player );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubSea923:65782 calling [BranchTrue]Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=WAWALAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubSea923:65782 calling Scene00004: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00005( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubSea923:65782 calling [BranchTrue]Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=WAWALAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubSea923:65782 calling Scene00006: Normal(Talk, TargetCanMove), id=STEERSMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubSea923:65782 calling Scene00007: Normal(Talk, TargetCanMove), id=SISIPU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubSea923:65782 calling Scene00008: Normal(Talk, TargetCanMove), id=WAWALAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubSea923:65782 calling Scene00009: Normal(Talk, TargetCanMove), id=ASCELYN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubSea923:65782 calling Scene00010: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00011( player );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubSea923:65782 calling [BranchTrue]Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubSea923:65782 calling Scene00012: Normal(Talk, TargetCanMove), id=STEERSMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubSea923:65782 calling Scene00013: Normal(Talk, TargetCanMove), id=SISIPU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "SubSea923:65782 calling Scene00014: Normal(Talk, TargetCanMove), id=WAWALAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "SubSea923:65782 calling Scene00015: Normal(Talk, TargetCanMove), id=ASCELYN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "SubSea923:65782 calling Scene00016: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=WAWALAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "SubSea923:65782 calling Scene00017: Normal(Talk, TargetCanMove), id=SISIPU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubSea923 );
