// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse112 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse112() : Sapphire::ScriptAPI::EventScript( 66722 ){}; 
  ~GaiUse112() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 5 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1006530
  //ACTOR1 = 1007722
  //ACTOR2 = 1003785
  //EOBJECT0 = 2002850
  //EOBJECT1 = 2002851
  //EOBJECT2 = 2002852
  //EOBJECT3 = 2002853
  //EVENTACTIONPROCESSUPPERLONG = 33
  //EVENTACTIONPROCESSUPPERMIDDLE = 32
  //EVENTACTIONPROCESSUPPERSHORT = 31
  //ITEM0 = 2001080

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SLAFBORN
        break;
      }
      case 1:
      {
        if( actor == 1007722 || actorId == 1007722 ) // ACTOR1 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
        }
        if( actor == 1006530 || actorId == 1006530 ) // ACTOR0 = SLAFBORN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=SLAFBORN
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BL max stack 4
      case 2:
      {
        if( actor == 2002850 || actorId == 2002850 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 4 )
          {
            Scene00004( player ); // Scene00004: Normal(None), id=unknown
            // +Callback Scene00005: Normal(None), id=unknown
          }
        }
        if( actor == 2002851 || actorId == 2002851 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 4 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
            // +Callback Scene00007: Normal(None), id=unknown
          }
        }
        if( actor == 2002852 || actorId == 2002852 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 4 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
            // +Callback Scene00009: Normal(None), id=unknown
          }
        }
        if( actor == 2002853 || actorId == 2002853 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 4 )
          {
            Scene00010( player ); // Scene00010: Normal(None), id=unknown
            // +Callback Scene00011: Normal(None), id=unknown
          }
        }
        if( actor == 1007722 || actorId == 1007722 ) // ACTOR1 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BL max stack 4
      case 255:
      {
        if( actor == 1003785 || actorId == 1003785 ) // ACTOR2 = TATARU
        {
          Scene00013( player ); // Scene00013: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TATARU
        }
        if( actor == 1007722 || actorId == 1007722 ) // ACTOR1 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 4 )
      if( player.getQuestUI8BH( getId() ) == 4 )
        if( player.getQuestUI8BH( getId() ) == 4 )
          if( player.getQuestUI8BH( getId() ) == 4 )
          {
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.updateQuest( getId(), 255 );
            player.setQuestUI8BL( getId(), 4 );
          }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse112:66722 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse112:66722 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse112:66722 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse112:66722 calling Scene00003: Normal(Talk, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse112:66722 calling Scene00004: Normal(None), id=unknown" );
    Scene00005( player );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse112:66722 calling [BranchTrue]Scene00005: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
    checkProgressSeq2( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse112:66722 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse112:66722 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
    checkProgressSeq2( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse112:66722 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse112:66722 calling [BranchTrue]Scene00009: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
    checkProgressSeq2( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse112:66722 calling Scene00010: Normal(None), id=unknown" );
    Scene00011( player );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse112:66722 calling [BranchTrue]Scene00011: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
    checkProgressSeq2( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse112:66722 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse112:66722 calling Scene00013: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00014( player );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse112:66722 calling [BranchTrue]Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse112:66722 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse112 );
