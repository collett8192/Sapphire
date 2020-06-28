// FFXIVTheMovie.ParserV3
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsa507 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsa507() : Sapphire::ScriptAPI::EventScript( 66295 ){}; 
  ~GaiUsa507() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 1 entries
  //SEQ_4, 3 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006211
  //ACTOR1 = 1006216
  //ACTOR2 = 1006212
  //ACTOR3 = 1006213
  //ACTOR4 = 1006214
  //ENEMY0 = 176
  //ITEM0 = 2000605
  //ITEM1 = 2000855

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HIHIRA
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALFAN
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 5
      case 2:
      {
        Scene00003( player ); // Scene00003: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00004: Normal(Talk, TargetCanMove), id=HIHIRA
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 5
      case 3:
      {
        Scene00005( player ); // Scene00005: NpcTrade(Talk), id=unknown
        // +Callback Scene00006: Normal(Talk, TargetCanMove), id=BEROLD
        break;
      }
      //seq 4 event item ITEM1 = UI8BH max stack 1
      case 4:
      {
        if( actor == 1006212 || actorId == 1006212 ) // ACTOR2 = OTELIN
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00007( player ); // Scene00007: NpcTrade(Talk), id=unknown
            // +Callback Scene00008: Normal(Talk, TargetCanMove), id=OTELIN
          }
        }
        if( actor == 1006213 || actorId == 1006213 ) // ACTOR3 = ARCAVIUS
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00009( player ); // Scene00009: NpcTrade(Talk), id=unknown
            // +Callback Scene00010: Normal(Talk, TargetCanMove), id=ARCAVIUS
          }
        }
        if( actor == 1006214 || actorId == 1006214 ) // ACTOR4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq4( player );
          }
        }
        break;
      }
      case 255:
      {
        Scene00011( player ); // Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIHIRA
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
    player.setQuestUI8BH( getId(), 5 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
    player.updateQuest( getId(), 4 );
    player.setQuestUI8BH( getId(), 1 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
        if( player.getQuestUI8AL( getId() ) == 3 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa507:66295 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsa507:66295 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HIHIRA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa507:66295 calling Scene00002: Normal(Talk, TargetCanMove), id=ALFAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa507:66295 calling Scene00003: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00004( player );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa507:66295 calling [BranchTrue]Scene00004: Normal(Talk, TargetCanMove), id=HIHIRA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa507:66295 calling Scene00005: NpcTrade(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00006( player );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa507:66295 calling [BranchTrue]Scene00006: Normal(Talk, TargetCanMove), id=BEROLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa507:66295 calling Scene00007: NpcTrade(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00008( player );
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa507:66295 calling [BranchTrue]Scene00008: Normal(Talk, TargetCanMove), id=OTELIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa507:66295 calling Scene00009: NpcTrade(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00010( player );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa507:66295 calling [BranchTrue]Scene00010: Normal(Talk, TargetCanMove), id=ARCAVIUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa507:66295 calling Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIHIRA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 11, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsa507 );
