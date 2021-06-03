// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKba321 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKba321() : Sapphire::ScriptAPI::EventScript( 68811 ){}; 
  ~LucKba321() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 1 entries
  //SEQ_4, 4 entries
  //SEQ_5, 4 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1030964
  //ACTOR1 = 1030135
  //ACTOR10 = 1031651
  //ACTOR2 = 1030136
  //ACTOR3 = 1030137
  //ACTOR4 = 1030138
  //ACTOR5 = 1030139
  //ACTOR6 = 1030140
  //ACTOR7 = 1030141
  //ACTOR8 = 1030142
  //ACTOR9 = 1030143
  //EOBJECT0 = 2010402
  //EOBJECT1 = 2010403
  //EVENTACTION0 = 50
  //LEVELENPCID0 = 7963529
  //LEVELENPCID1 = 7963530
  //LEVELENPCID2 = 7963531
  //LEVELENPCID3 = 7963546
  //LEVELENPCID4 = 7963547
  //LEVELENPCID5 = 7963549
  //LOCACTOR0 = 1030128

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=LUEREEQ
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=LUEREEQ
        break;
      }
      case 2:
      {
        Scene00004( player ); // Scene00004: Normal(SystemTalk), id=unknown
        break;
      }
      case 3:
      {
        Scene00006( player ); // Scene00006: Normal(SystemTalk), id=unknown
        break;
      }
      case 4:
      {
        if( param1 == 1030136 || param2 == 1030136 ) // ACTOR2 = LUEREEQ
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=LUEREEQ
          }
          break;
        }
        if( param1 == 1030137 || param2 == 1030137 ) // ACTOR3 = LANBYRD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LANBYRD
          break;
        }
        if( param1 == 1030138 || param2 == 1030138 ) // ACTOR4 = DRAHNCONJURER
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=DRAHNCONJURER
          break;
        }
        if( param1 == 1030139 || param2 == 1030139 ) // ACTOR5 = GALDJENTGLADIATOR
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=GALDJENTGLADIATOR
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1030140 || param2 == 1030140 ) // ACTOR6 = LUEREEQ
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=LUEREEQ
          }
          break;
        }
        if( param1 == 1030141 || param2 == 1030141 ) // ACTOR7 = LUEREEQFATHER
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=LUEREEQFATHER
          break;
        }
        if( param1 == 1030142 || param2 == 1030142 ) // ACTOR8 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030143 || param2 == 1030143 ) // ACTOR9 = IMPASSIVESERVANT
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=IMPASSIVESERVANT
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030964 || param2 == 1030964 ) // ACTOR0 = LUEREEQ
        {
          Scene00015( player ); // Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, Menu), id=LUEREEQ
          break;
        }
        if( param1 == 1031651 || param2 == 1031651 ) // ACTOR10 = LUEREEQFATHER
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=LUEREEQFATHER
          break;
        }
        if( param1 == 1030142 || param2 == 1030142 ) // ACTOR8 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030143 || param2 == 1030143 ) // ACTOR9 = IMPASSIVESERVANT
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=IMPASSIVESERVANT
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKba321:68811 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKba321:68811 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=LUEREEQ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKba321:68811 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=LUEREEQ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKba321:68811 calling Scene00004: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKba321:68811 calling Scene00006: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKba321:68811 calling Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=LUEREEQ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKba321:68811 calling Scene00008: Normal(Talk, TargetCanMove), id=LANBYRD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKba321:68811 calling Scene00009: Normal(Talk, TargetCanMove), id=DRAHNCONJURER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKba321:68811 calling Scene00010: Normal(Talk, TargetCanMove), id=GALDJENTGLADIATOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKba321:68811 calling Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=LUEREEQ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKba321:68811 calling Scene00012: Normal(Talk, TargetCanMove), id=LUEREEQFATHER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKba321:68811 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKba321:68811 calling Scene00014: Normal(Talk, TargetCanMove), id=IMPASSIVESERVANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKba321:68811 calling Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, Menu), id=LUEREEQ" );
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
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKba321:68811 calling Scene00016: Normal(Talk, TargetCanMove), id=LUEREEQFATHER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKba321:68811 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKba321:68811 calling Scene00018: Normal(Talk, TargetCanMove), id=IMPASSIVESERVANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKba321 );
