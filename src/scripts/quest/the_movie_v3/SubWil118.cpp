// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil118 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil118() : Sapphire::ScriptAPI::EventScript( 66163 ){}; 
  ~SubWil118() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1003936
  //EOBJECT0 = 2001413
  //EOBJECT1 = 2001414
  //EOBJECT2 = 2001415
  //EOBJECT3 = 2001416
  //EOBJECT4 = 2001417
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000400

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=AIRELL
        break;
      }
      //seq 1 event item ITEM0 = UI8DH max stack ?
      case 1:
      {
        if( actor == 2001413 || actorId == 2001413 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00001( player ); // Scene00001: Normal(Inventory), id=unknown
            // +Callback Scene00002: Normal(None), id=unknown
          }
        }
        if( actor == 2001414 || actorId == 2001414 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
            // +Callback Scene00004: Normal(Inventory), id=unknown
          }
          else
          {
            Scene00005( player ); // Scene00005: Normal(None), id=unknown
          }
        }
        if( actor == 2001415 || actorId == 2001415 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
            // +Callback Scene00007: Normal(Inventory), id=unknown
          }
          else
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
          }
        }
        if( actor == 2001416 || actorId == 2001416 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(None), id=unknown
            // +Callback Scene00010: Normal(Inventory), id=unknown
          }
          else
          {
            Scene00011( player ); // Scene00011: Normal(None), id=unknown
          }
        }
        if( actor == 2001417 || actorId == 2001417 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8CL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(None), id=unknown
            // +Callback Scene00013: Normal(Inventory), id=unknown
          }
          else
          {
            Scene00014( player ); // Scene00014: Normal(None), id=unknown
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      case 255:
      {
        if( actor == 1003936 || actorId == 1003936 ) // ACTOR0 = AIRELL
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          // +Callback Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AIRELL
        }
        if( actor == 2001413 || actorId == 2001413 ) // EOBJECT0 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          // +Callback Scene00018: Normal(None), id=unknown
        }
        if( actor == 2001414 || actorId == 2001414 ) // EOBJECT1 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          // +Callback Scene00020: Normal(None), id=unknown
        }
        if( actor == 2001415 || actorId == 2001415 ) // EOBJECT2 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          // +Callback Scene00022: Normal(None), id=unknown
        }
        if( actor == 2001416 || actorId == 2001416 ) // EOBJECT3 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          // +Callback Scene00024: Normal(None), id=unknown
        }
        if( actor == 2001417 || actorId == 2001417 ) // EOBJECT4 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          // +Callback Scene00026: Normal(None), id=unknown
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
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
          if( player.getQuestUI8CH( getId() ) == 1 )
            if( player.getQuestUI8CL( getId() ) == 1 )
            {
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8BH( getId(), 0 );
              player.setQuestUI8BL( getId(), 0 );
              player.setQuestUI8CH( getId(), 0 );
              player.setQuestUI8CL( getId(), 0 );
              player.setQuestUI8DH( getId(), 0 );
              player.updateQuest( getId(), 255 );
            }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=AIRELL" );
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
    player.sendDebug( "SubWil118:66163 calling Scene00001: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling [BranchTrue]Scene00002: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling Scene00003: Normal(None), id=unknown" );
    Scene00004( player );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling [BranchTrue]Scene00004: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling [BranchFalse]Scene00005: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling [BranchTrue]Scene00007: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling [BranchFalse]Scene00008: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling [BranchTrue]Scene00010: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling [BranchFalse]Scene00011: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling Scene00012: Normal(None), id=unknown" );
    Scene00013( player );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling [BranchTrue]Scene00013: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling [BranchFalse]Scene00014: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling Scene00015: Normal(None), id=unknown" );
    Scene00016( player );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling [BranchTrue]Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AIRELL" );
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
    player.sendDebug( "SubWil118:66163 calling Scene00017: Normal(None), id=unknown" );
    Scene00018( player );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling [BranchTrue]Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling Scene00019: Normal(None), id=unknown" );
    Scene00020( player );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling [BranchTrue]Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling Scene00021: Normal(None), id=unknown" );
    Scene00022( player );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling [BranchTrue]Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling Scene00023: Normal(None), id=unknown" );
    Scene00024( player );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling [BranchTrue]Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling Scene00025: Normal(None), id=unknown" );
    Scene00026( player );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "SubWil118:66163 calling [BranchTrue]Scene00026: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( SubWil118 );
