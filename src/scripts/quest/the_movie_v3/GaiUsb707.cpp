// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb707 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb707() : Sapphire::ScriptAPI::EventScript( 66438 ){}; 
  ~GaiUsb707() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1006402
  //EOBJECT0 = 2002126
  //EOBJECT1 = 2002127
  //EOBJECT2 = 2002128
  //EOBJECT3 = 2002129
  //EOBJECT4 = 2002130
  //EOBJECT5 = 2002561
  //EOBJECT6 = 2002562
  //EOBJECT7 = 2002563
  //EOBJECT8 = 2002564
  //EOBJECT9 = 2002565
  //ITEM0 = 2000706

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=ARTHURIOUX
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( actor == 2002126 || actorId == 2002126 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00001( player ); // Scene00001: Normal(None), id=unknown
          }
        }
        if( actor == 2002127 || actorId == 2002127 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00002( player ); // Scene00002: Normal(Inventory), id=unknown
            // +Callback Scene00003: Normal(None), id=unknown
          }
        }
        if( actor == 2002128 || actorId == 2002128 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00004( player ); // Scene00004: Normal(Inventory), id=unknown
            // +Callback Scene00005: Normal(None), id=unknown
          }
        }
        if( actor == 2002129 || actorId == 2002129 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00006( player ); // Scene00006: Normal(Inventory), id=unknown
            // +Callback Scene00007: Normal(None), id=unknown
          }
        }
        if( actor == 2002130 || actorId == 2002130 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00008( player ); // Scene00008: Normal(Inventory), id=unknown
            // +Callback Scene00009: Normal(None), id=unknown
          }
          else
          {
            Scene00010( player ); // Scene00010: Normal(Inventory), id=unknown
          }
        }
        break;
      }
      case 255:
      {
        if( actor == 1006402 || actorId == 1006402 ) // ACTOR0 = ARTHURIOUX
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          // +Callback Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ARTHURIOUX
        }
        if( actor == 2002561 || actorId == 2002561 ) // EOBJECT5 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( actor == 2002562 || actorId == 2002562 ) // EOBJECT6 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        if( actor == 2002563 || actorId == 2002563 ) // EOBJECT7 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( actor == 2002564 || actorId == 2002564 ) // EOBJECT8 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        if( actor == 2002565 || actorId == 2002565 ) // EOBJECT9 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
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
              player.updateQuest( getId(), 255 );
            }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb707:66438 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=ARTHURIOUX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb707:66438 calling Scene00001: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb707:66438 calling Scene00002: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb707:66438 calling [BranchTrue]Scene00003: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb707:66438 calling Scene00004: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb707:66438 calling [BranchTrue]Scene00005: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb707:66438 calling Scene00006: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb707:66438 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb707:66438 calling Scene00008: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb707:66438 calling [BranchTrue]Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb707:66438 calling [BranchFalse]Scene00010: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb707:66438 calling Scene00011: Normal(None), id=unknown" );
    Scene00012( player );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb707:66438 calling [BranchTrue]Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ARTHURIOUX" );
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

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb707:66438 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb707:66438 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb707:66438 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb707:66438 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb707:66438 calling Scene00017: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsb707 );
