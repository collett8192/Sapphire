// FFXIVTheMovie.ParserV3
//fix: skip dungeon
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse311 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse311() : Sapphire::ScriptAPI::EventScript( 66988 ){}; 
  ~GaiUse311() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 4 entries
  //SEQ_2, 1 entries
  //SEQ_3, 1 entries
  //SEQ_255, 1 entries

  //ACTIONTIMELINEEVENTBYEBYE = 962
  //ACTOR0 = 1009119
  //ACTOR1 = 1009117
  //ACTOR2 = 1009120
  //ACTOR3 = 1009121
  //ACTOR4 = 1009116
  //ACTOR5 = 1009124
  //ACTOR6 = 1009125
  //ACTOR7 = 1009126
  //ACTOR8 = 5010000
  //ACTOR9 = 1009097
  //CUTSCENEN01 = 534
  //CUTSCENEN02 = 535
  //EVENTRANGE0 = 4841610
  //EVENTACTIONSEARCH = 1
  //INSTANCEDUNGEON0 = 20022
  //LEVELIDNPC01 = 4868016
  //LEVELIDNPC02 = 4868018
  //LEVELIDNPC03 = 4868019
  //LEVELIDNPC04 = 4868015
  //LEVELIDNPC05 = 4841607
  //LEVELIDNPC06 = 4841608
  //LEVELIDNPC07 = 4841609
  //POPRANGE0 = 4868026
  //TERRITORYTYPE0 = 152
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKDUNGEONRAMUHHARD = 222

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1009119 || actorId == 1009119 ) // ACTOR0 = PAPALYMO
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=PAPALYMO
        }
        if( actor == 1009117 || actorId == 1009117 ) // ACTOR1 = MAXIO
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MAXIO
        }
        if( actor == 1009120 || actorId == 1009120 ) // ACTOR2 = THANCRED
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 1009121 || actorId == 1009121 ) // ACTOR3 = YSHTOLA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1009116 || actorId == 1009116 ) // ACTOR4 = YDA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YDA
        }
        break;
      }
      case 1:
      {
        if( actor == 4841610 || actorId == 4841610 ) // EVENTRANGE0 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(CutScene), id=unknown
        }
        if( actor == 1009124 || actorId == 1009124 ) // ACTOR5 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(FadeIn), id=unknown
        }
        if( actor == 1009125 || actorId == 1009125 ) // ACTOR6 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        if( actor == 1009126 || actorId == 1009126 ) // ACTOR7 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        Scene00010( player ); // Scene00010: Normal(None), id=unknown
        break;
      }
      case 3:
      {
        Scene00011( player ); // Scene00011: Normal(CutScene), id=unknown
        break;
      }
      case 255:
      {
        Scene00012( player ); // Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LIEUTENANT01448
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse311:66988 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse311:66988 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse311:66988 calling Scene00002: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse311:66988 calling Scene00003: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse311:66988 calling Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse311:66988 calling Scene00005: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse311:66988 calling Scene00006: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse311:66988 calling Scene00007: Normal(FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse311:66988 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse311:66988 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse311:66988 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse311:66988 calling Scene00011: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse311:66988 calling Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LIEUTENANT01448" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse311 );
