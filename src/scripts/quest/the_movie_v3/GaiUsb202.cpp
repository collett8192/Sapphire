// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb202 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb202() : Sapphire::ScriptAPI::EventScript( 66369 ){}; 
  ~GaiUsb202() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_2, 8 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1006269
  //ENEMY0 = 4293253
  //ENEMY1 = 4293254
  //EOBJECT0 = 2002050
  //EOBJECT1 = 2002291
  //EOBJECT2 = 2002292
  //EOBJECT3 = 2002293
  //EOBJECT4 = 2002294
  //EOBJECT5 = 2002051
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONWAITINGSHOR = 11
  //ITEM0 = 2000650

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=KUZAITAZAI
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( actor == 2002050 || actorId == 2002050 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00002( player ); // Scene00002: Normal(Inventory), id=unknown
            // +Callback Scene00003: Normal(None), id=unknown
          }
        }
        if( actor == 2002291 || actorId == 2002291 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00004( player ); // Scene00004: Normal(Inventory), id=unknown
            // +Callback Scene00005: Normal(None), id=unknown
          }
        }
        if( actor == 2002292 || actorId == 2002292 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00006( player ); // Scene00006: Normal(Inventory), id=unknown
            // +Callback Scene00007: Normal(None), id=unknown
          }
        }
        if( actor == 2002293 || actorId == 2002293 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00008( player ); // Scene00008: Normal(Inventory), id=unknown
            // +Callback Scene00009: Normal(None), id=unknown
          }
        }
        if( actor == 2002294 || actorId == 2002294 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00010( player ); // Scene00010: Normal(Inventory), id=unknown
            // +Callback Scene00011: Normal(None), id=unknown
          }
        }
        break;
      }
      case 2:
      {
        if( actor == 2002051 || actorId == 2002051 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00012( player ); // Scene00012: Normal(None), id=unknown
            // +Callback Scene00013: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4293253 || actorId == 4293253 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4293254 || actorId == 4293254 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 2002050 || actorId == 2002050 ) // EOBJECT0 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          // +Callback Scene00015: Normal(None), id=unknown
        }
        if( actor == 2002291 || actorId == 2002291 ) // EOBJECT1 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          // +Callback Scene00017: Normal(None), id=unknown
        }
        if( actor == 2002292 || actorId == 2002292 ) // EOBJECT2 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          // +Callback Scene00019: Normal(None), id=unknown
        }
        if( actor == 2002293 || actorId == 2002293 ) // EOBJECT3 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          // +Callback Scene00021: Normal(None), id=unknown
        }
        if( actor == 2002294 || actorId == 2002294 ) // EOBJECT4 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          // +Callback Scene00023: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1006269 || actorId == 1006269 ) // ACTOR0 = KUZAITAZAI
        {
          Scene00024( player ); // Scene00024: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KUZAITAZAI
        }
        if( actor == 2002050 || actorId == 2002050 ) // EOBJECT0 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          // +Callback Scene00026: Normal(None), id=unknown
        }
        if( actor == 2002291 || actorId == 2002291 ) // EOBJECT1 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          // +Callback Scene00028: Normal(None), id=unknown
        }
        if( actor == 2002292 || actorId == 2002292 ) // EOBJECT2 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          // +Callback Scene00030: Normal(None), id=unknown
        }
        if( actor == 2002293 || actorId == 2002293 ) // EOBJECT3 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          // +Callback Scene00032: Normal(None), id=unknown
        }
        if( actor == 2002294 || actorId == 2002294 ) // EOBJECT4 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          // +Callback Scene00034: Normal(None), id=unknown
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

private:
  void checkProgressSeq0( Entity::Player& player )
  {
    player.updateQuest( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 5 )
      if( player.getQuestUI8AL( getId() ) == 5 )
        if( player.getQuestUI8AL( getId() ) == 5 )
          if( player.getQuestUI8AL( getId() ) == 5 )
            if( player.getQuestUI8AL( getId() ) == 5 )
            {
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8BH( getId(), 0 );
              player.updateQuest( getId(), 2 );
            }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb202:66369 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=KUZAITAZAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling Scene00002: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling [BranchTrue]Scene00003: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling Scene00004: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling [BranchTrue]Scene00005: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling Scene00006: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling Scene00008: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling [BranchTrue]Scene00009: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling Scene00010: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling [BranchTrue]Scene00011: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling Scene00012: Normal(None), id=unknown" );
    Scene00013( player );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling [BranchTrue]Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling Scene00014: Normal(None), id=unknown" );
    Scene00015( player );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling [BranchTrue]Scene00015: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling Scene00016: Normal(None), id=unknown" );
    Scene00017( player );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling [BranchTrue]Scene00017: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling Scene00018: Normal(None), id=unknown" );
    Scene00019( player );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling [BranchTrue]Scene00019: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling Scene00020: Normal(None), id=unknown" );
    Scene00021( player );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling [BranchTrue]Scene00021: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling Scene00022: Normal(None), id=unknown" );
    Scene00023( player );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling [BranchTrue]Scene00023: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling Scene00024: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KUZAITAZAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling Scene00025: Normal(None), id=unknown" );
    Scene00026( player );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling [BranchTrue]Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling Scene00027: Normal(None), id=unknown" );
    Scene00028( player );
  }
  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling [BranchTrue]Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling Scene00029: Normal(None), id=unknown" );
    Scene00030( player );
  }
  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling [BranchTrue]Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling Scene00031: Normal(None), id=unknown" );
    Scene00032( player );
  }
  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling [BranchTrue]Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling Scene00033: Normal(None), id=unknown" );
    Scene00034( player );
  }
  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb202:66369 calling [BranchTrue]Scene00034: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsb202 );
