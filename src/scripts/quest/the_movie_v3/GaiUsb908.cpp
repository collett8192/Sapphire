// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb908 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb908() : Sapphire::ScriptAPI::EventScript( 66467 ){}; 
  ~GaiUsb908() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006456
  //EOBJECT0 = 2002159
  //EOBJECT1 = 2002160
  //EOBJECT2 = 2002161
  //EOBJECT3 = 2002162
  //EOBJECT4 = 2002163
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONSEARCHMIDDLE = 3

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CHAUNOLLET
        break;
      }
      case 1:
      {
        if( actor == 2002159 || actorId == 2002159 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(None), id=unknown
            // +Callback Scene00003: Normal(None), id=unknown
          }
        }
        if( actor == 2002160 || actorId == 2002160 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(None), id=unknown
            // +Callback Scene00005: Normal(None), id=unknown
          }
        }
        if( actor == 2002161 || actorId == 2002161 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
            // +Callback Scene00007: Normal(None), id=unknown
          }
        }
        if( actor == 2002162 || actorId == 2002162 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
            // +Callback Scene00009: Normal(None), id=unknown
          }
        }
        if( actor == 2002163 || actorId == 2002163 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8CL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(None), id=unknown
            // +Callback Scene00011: Normal(None), id=unknown
          }
        }
        break;
      }
      case 255:
      {
        Scene00012( player ); // Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CHAUNOLLET
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
              player.updateQuest( getId(), 255 );
            }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb908:66467 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb908:66467 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CHAUNOLLET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb908:66467 calling Scene00002: Normal(None), id=unknown" );
    Scene00003( player );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb908:66467 calling [BranchTrue]Scene00003: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb908:66467 calling Scene00004: Normal(None), id=unknown" );
    Scene00005( player );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb908:66467 calling [BranchTrue]Scene00005: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb908:66467 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb908:66467 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb908:66467 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb908:66467 calling [BranchTrue]Scene00009: Normal(None), id=unknown" );
    player.setQuestUI8CH( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb908:66467 calling Scene00010: Normal(None), id=unknown" );
    Scene00011( player );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb908:66467 calling [BranchTrue]Scene00011: Normal(None), id=unknown" );
    player.setQuestUI8CL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb908:66467 calling Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CHAUNOLLET" );
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

EXPOSE_SCRIPT( GaiUsb908 );