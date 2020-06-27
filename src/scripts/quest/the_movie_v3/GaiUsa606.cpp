// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsa606 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsa606() : Sapphire::ScriptAPI::EventScript( 66304 ){}; 
  ~GaiUsa606() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 9 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006236
  //ACTOR1 = 1006237
  //ENEMY0 = 4278319
  //ENEMY1 = 4278320
  //ENEMY2 = 4278321
  //EOBJECT0 = 2001969
  //EOBJECT1 = 2001970
  //EOBJECT2 = 2001971
  //EOBJECT3 = 2001972
  //EOBJECT4 = 2002269
  //EOBJECT5 = 2001973
  //EVENTACTIONPROCESSUPPERMIDDLE = 32
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000608

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=DEIDRA
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=FAWKES
        break;
      }
      //seq 2 event item ITEM0 = UI8DL max stack 6
      case 2:
      {
        if( actor == 2001969 || actorId == 2001969 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
            // +Callback Scene00004: Normal(None), id=unknown
          }
        }
        if( actor == 2001970 || actorId == 2001970 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(None), id=unknown
            // +Callback Scene00006: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4278319 || actorId == 4278319 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 2001971 || actorId == 2001971 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
            // +Callback Scene00008: Normal(None), id=unknown
          }
        }
        if( actor == 2001972 || actorId == 2001972 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8CL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(None), id=unknown
            // +Callback Scene00010: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4278320 || actorId == 4278320 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 2002269 || actorId == 2002269 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(None), id=unknown
            // +Callback Scene00012: Normal(None), id=unknown
          }
        }
        if( actor == 2001973 || actorId == 2001973 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8DH( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(None), id=unknown
            // +Callback Scene00014: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4278321 || actorId == 4278321 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 6
      case 255:
      {
        Scene00015( player ); // Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=FAWKES
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
      if( player.getQuestUI8CH( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
          if( player.getQuestUI8CL( getId() ) == 1 )
            if( player.getQuestUI8BL( getId() ) == 1 )
              if( player.getQuestUI8DH( getId() ) == 1 )
              {
                player.setQuestUI8AL( getId(), 0 );
                player.setQuestUI8CH( getId(), 0 );
                player.setQuestUI8BH( getId(), 0 );
                player.setQuestUI8CL( getId(), 0 );
                player.setQuestUI8BL( getId(), 0 );
                player.setQuestUI8DH( getId(), 0 );
                player.setQuestUI8DL( getId(), 0 );
                player.updateQuest( getId(), 255 );
                player.setQuestUI8BH( getId(), 6 );
              }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa606:66304 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsa606:66304 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=DEIDRA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa606:66304 calling Scene00002: Normal(Talk, TargetCanMove), id=FAWKES" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa606:66304 calling Scene00003: Normal(None), id=unknown" );
    Scene00004( player );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa606:66304 calling [BranchTrue]Scene00004: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa606:66304 calling Scene00005: Normal(None), id=unknown" );
    Scene00006( player );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa606:66304 calling [BranchTrue]Scene00006: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa606:66304 calling Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa606:66304 calling [BranchTrue]Scene00008: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa606:66304 calling Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa606:66304 calling [BranchTrue]Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa606:66304 calling Scene00011: Normal(None), id=unknown" );
    Scene00012( player );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa606:66304 calling [BranchTrue]Scene00012: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa606:66304 calling Scene00013: Normal(None), id=unknown" );
    Scene00014( player );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa606:66304 calling [BranchTrue]Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8DH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa606:66304 calling Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsa606:66304 calling [BranchTrue]Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=FAWKES" );
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
};

EXPOSE_SCRIPT( GaiUsa606 );
