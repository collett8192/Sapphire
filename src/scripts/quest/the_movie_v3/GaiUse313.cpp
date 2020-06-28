// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse313 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse313() : Sapphire::ScriptAPI::EventScript( 66990 ){}; 
  ~GaiUse313() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 2 entries
  //SEQ_4, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1008969
  //ACTOR1 = 1006530
  //ACTOR2 = 1009076
  //ENEMY0 = 4867448
  //EOBJECT0 = 2004144
  //EVENTRANGE0 = 4867451
  //EVENTACTIONRESCUEUPPERMIDDLE = 39
  //EVENTACTIONSEARCH = 1
  //LOCACTION1 = 1041
  //LOCACTOR0 = 1004145
  //LOCEOBJ1 = 2004499
  //LOCFACE1 = 617
  //LOCFACE2 = 611
  //LOCFACE3 = 605
  //LOCPOSCAM1 = 4891203
  //LOCPOSEOBJ1 = 4891195
  //LOCSE1 = 44
  //LOCSE2 = 45
  //QSTBANAMA005 = 66757
  //QSTBANIXA005 = 67026
  //QSTBANKOB005 = 66860
  //QSTBANSAH005 = 66914
  //QSTGAIUSD101 = 66695
  //QSTGAIUSD203 = 66737

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MINFILIA
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=SLAFBORN
        break;
      }
      case 2:
      {
        if( actor == 4867451 || actorId == 4867451 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4867448 || actorId == 4867448 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 2004144 || actorId == 2004144 ) // EOBJECT0 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          // +Callback Scene00005: Normal(None), id=unknown
        }
        if( actor == 1009076 || actorId == 1009076 ) // ACTOR2 = ADVENTURER01454
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ADVENTURER01454
        }
        if( actor == 1006530 || actorId == 1006530 ) // ACTOR1 = SLAFBORN
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=SLAFBORN
        }
        break;
      }
      case 3:
      {
        if( actor == 1009076 || actorId == 1009076 ) // ACTOR2 = ADVENTURER01454
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
            // +Callback Scene00009: Normal(Talk, TargetCanMove), id=ADVENTURER01454
          }
        }
        if( actor == 1006530 || actorId == 1006530 ) // ACTOR1 = SLAFBORN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=SLAFBORN
        }
        break;
      }
      case 4:
      {
        if( actor == 1009076 || actorId == 1009076 ) // ACTOR2 = ADVENTURER01454
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ADVENTURER01454
            // +Callback Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=ADVENTURER01454
          }
          else
          {
            Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ADVENTURER01454
          }
        }
        if( actor == 1006530 || actorId == 1006530 ) // ACTOR1 = SLAFBORN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=SLAFBORN
        }
        break;
      }
      case 255:
      {
        Scene00015( player ); // Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SLAFBORN
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
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
    player.sendDebug( "GaiUse313:66990 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse313:66990 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse313:66990 calling Scene00002: Normal(Talk, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse313:66990 calling Scene00003: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse313:66990 calling Scene00004: Normal(None), id=unknown" );
    Scene00005( player );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse313:66990 calling [BranchTrue]Scene00005: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse313:66990 calling Scene00006: Normal(Talk, TargetCanMove), id=ADVENTURER01454" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse313:66990 calling Scene00007: Normal(Talk, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse313:66990 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse313:66990 calling [BranchTrue]Scene00009: Normal(Talk, TargetCanMove), id=ADVENTURER01454" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse313:66990 calling Scene00010: Normal(Talk, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse313:66990 calling Scene00011: Normal(Talk, TargetCanMove), id=ADVENTURER01454" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse313:66990 calling [BranchTrue]Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=ADVENTURER01454" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse313:66990 calling [BranchFalse]Scene00013: Normal(Talk, TargetCanMove), id=ADVENTURER01454" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse313:66990 calling Scene00014: Normal(Talk, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse313:66990 calling Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse313 );
