// FFXIVTheMovie.ParserV3
//fix: skip dungeon and quest battle
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ManFst205 : public Sapphire::ScriptAPI::EventScript
{
public:
  ManFst205() : Sapphire::ScriptAPI::EventScript( 66196 ){}; 
  ~ManFst205() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 4 entries
  //SEQ_3, 3 entries
  //SEQ_4, 2 entries
  //SEQ_5, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1001353
  //ACTOR1 = 1004621
  //ACTOR2 = 1002285
  //ACTOR3 = 1004623
  //ACTOR4 = 1004624
  //CUTSCENE04FST = 79
  //CUTSCENE04SEA = 215
  //CUTSCENE04WIL = 216
  //EOBJECT0 = 2001854
  //INSTANCEDUNGEON0 = 3
  //LOCACTOR0 = 1003995
  //LOCACTOR1 = 1004618
  //LOCACTOR2 = 1005137
  //QUESTBATTLE0 = 44
  //SEQ0ACTOR0LQ = 90
  //TERRITORYTYPE0 = 274
  //TERRITORYTYPE1 = 130
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKIMAGEDUNGEONCOPPERBELL = 75

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MOMODI
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=PAINTEDMESA
        break;
      }
      case 2:
      {
        if( actor == 1002285 || actorId == 1002285 ) // ACTOR2 = STONETORCH
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, Message, TargetCanMove), id=STONETORCH
          }
        }
        if( actor == 1004623 || actorId == 1004623 ) // ACTOR3 = ISILDAURE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ISILDAURE
        }
        if( actor == 1004624 || actorId == 1004624 ) // ACTOR4 = ALIANNE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALIANNE
        }
        if( actor == 1004621 || actorId == 1004621 ) // ACTOR1 = PAINTEDMESA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=PAINTEDMESA
        }
        break;
      }
      case 3:
      {
        if( actor == 1004623 || actorId == 1004623 ) // ACTOR3 = ISILDAURE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ISILDAURE
        }
        if( actor == 1004624 || actorId == 1004624 ) // ACTOR4 = ALIANNE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALIANNE
        }
        if( actor == 1002285 || actorId == 1002285 ) // ACTOR2 = STONETORCH
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=STONETORCH
        }
        break;
      }
      case 4:
      {
        if( actor == 1004621 || actorId == 1004621 ) // ACTOR1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(QuestBattle, YesNo), id=unknown
          }
        }
        if( actor == 2001854 || actorId == 2001854 ) // EOBJECT0 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        break;
      }
      case 5:
      {
        Scene00012( player ); // Scene00012: Normal(CutScene), id=unknown
        break;
      }
      case 255:
      {
        Scene00013( player ); // Scene00013: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=MOMODI
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "ManFst205:66196 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "ManFst205:66196 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MOMODI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "ManFst205:66196 calling Scene00002: Normal(Talk, TargetCanMove), id=PAINTEDMESA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "ManFst205:66196 calling Scene00003: Normal(Talk, Message, TargetCanMove), id=STONETORCH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "ManFst205:66196 calling Scene00004: Normal(Talk, TargetCanMove), id=ISILDAURE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "ManFst205:66196 calling Scene00005: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "ManFst205:66196 calling Scene00006: Normal(Talk, TargetCanMove), id=PAINTEDMESA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "ManFst205:66196 calling Scene00007: Normal(Talk, TargetCanMove), id=ISILDAURE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "ManFst205:66196 calling Scene00008: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "ManFst205:66196 calling Scene00009: Normal(Talk, TargetCanMove), id=STONETORCH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "ManFst205:66196 calling Scene00010: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00012( player );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "ManFst205:66196 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "ManFst205:66196 calling Scene00012: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "ManFst205:66196 calling Scene00013: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=MOMODI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( ManFst205 );
