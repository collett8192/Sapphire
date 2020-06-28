// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb805 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb805() : Sapphire::ScriptAPI::EventScript( 66450 ){}; 
  ~GaiUsb805() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 10 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1006430
  //ACTOR1 = 1006431
  //ENEMY0 = 4293168
  //ENEMY1 = 4293169
  //ENEMY2 = 4293167
  //EOBJECT0 = 2002409
  //EOBJECT1 = 2002410
  //EOBJECT2 = 2002411
  //EOBJECT3 = 2002412
  //EOBJECT4 = 2002413
  //EOBJECT5 = 2002414
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000717

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=JULINE
        break;
      }
      //seq 1 event item ITEM0 = UI8DL max stack 3
      case 1:
      {
        if( actor == 2002409 || actorId == 2002409 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(None), id=unknown
          }
        }
        if( actor == 2002410 || actorId == 2002410 ) // EOBJECT1 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(Message), id=unknown
          // +Callback Scene00004: Normal(None), id=unknown
        }
        if( actor == 4293168 || actorId == 4293168 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 2002411 || actorId == 2002411 ) // EOBJECT2 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 4293169 || actorId == 4293169 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 2002412 || actorId == 2002412 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
            // +Callback Scene00007: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 2002413 || actorId == 2002413 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
            // +Callback Scene00009: Normal(Message), id=unknown
          }
        }
        if( actor == 2002414 || actorId == 2002414 ) // EOBJECT5 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          // +Callback Scene00011: Normal(Message), id=unknown
        }
        if( actor == 4293167 || actorId == 4293167 ) // ENEMY2 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          // +Callback Scene00013: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 1006431 || actorId == 1006431 ) // ACTOR1 = MATIGNIANT
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=MATIGNIANT
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 3
      case 255:
      {
        if( actor == 1006430 || actorId == 1006430 ) // ACTOR0 = JULINE
        {
          Scene00015( player ); // Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=JULINE
        }
        if( actor == 1006431 || actorId == 1006431 ) // ACTOR1 = MATIGNIANT
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=MATIGNIANT
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
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8DL( getId(), 0 );
          player.updateQuest( getId(), 255 );
          player.setQuestUI8BH( getId(), 3 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb805:66450 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb805:66450 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=JULINE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb805:66450 calling Scene00002: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb805:66450 calling Scene00003: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb805:66450 calling [BranchTrue]Scene00004: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb805:66450 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb805:66450 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb805:66450 calling [BranchTrue]Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb805:66450 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb805:66450 calling [BranchTrue]Scene00009: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb805:66450 calling Scene00010: Normal(None), id=unknown" );
    Scene00011( player );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb805:66450 calling [BranchTrue]Scene00011: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb805:66450 calling Scene00012: Normal(None), id=unknown" );
    Scene00013( player );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb805:66450 calling [BranchTrue]Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb805:66450 calling Scene00014: Normal(Talk, TargetCanMove), id=MATIGNIANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb805:66450 calling Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00016( player );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb805:66450 calling [BranchTrue]Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=JULINE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb805:66450 calling Scene00017: Normal(Talk, TargetCanMove), id=MATIGNIANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsb805 );