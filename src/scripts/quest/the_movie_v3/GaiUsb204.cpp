// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb204 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb204() : Sapphire::ScriptAPI::EventScript( 66371 ){}; 
  ~GaiUsb204() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 9 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006270
  //ENEMY0 = 4293262
  //ENEMY1 = 4293263
  //ENEMY2 = 4293264
  //ENEMY3 = 4293265
  //ENEMY4 = 4293266
  //ENEMY5 = 4293267
  //EOBJECT0 = 2002053
  //EOBJECT1 = 2002054
  //EOBJECT2 = 2002055
  //ITEM0 = 2000651

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=FYRILSUNN
        break;
      }
      //seq 1 event item ITEM0 = UI8CH max stack ?
      case 1:
      {
        if( actor == 2002053 || actorId == 2002053 ) // EOBJECT0 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(Inventory), id=unknown
          // +Callback Scene00003: Normal(Message, PopBNpc, QuestGimmickReaction), id=unknown
        }
        if( actor == 4293262 || actorId == 4293262 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4293263 || actorId == 4293263 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 2002054 || actorId == 2002054 ) // EOBJECT1 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(Inventory), id=unknown
          // +Callback Scene00005: Normal(Message, PopBNpc, QuestGimmickReaction), id=unknown
        }
        if( actor == 4293264 || actorId == 4293264 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 4293265 || actorId == 4293265 ) // ENEMY3 = unknown
        {
          // empty entry
        }
        if( actor == 2002055 || actorId == 2002055 ) // EOBJECT2 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(Inventory), id=unknown
          // +Callback Scene00007: Normal(Message, PopBNpc, QuestGimmickReaction), id=unknown
        }
        if( actor == 4293266 || actorId == 4293266 ) // ENEMY4 = unknown
        {
          // empty entry
        }
        if( actor == 4293267 || actorId == 4293267 ) // ENEMY5 = unknown
        {
          // empty entry
        }
        break;
      }
      case 255:
      {
        Scene00008( player ); // Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=FYRILSUNN
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
    player.setQuestUI8CH( getId(), 0 );
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb204:66371 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb204:66371 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=FYRILSUNN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb204:66371 calling Scene00002: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb204:66371 calling [BranchTrue]Scene00003: Normal(Message, PopBNpc, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb204:66371 calling Scene00004: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb204:66371 calling [BranchTrue]Scene00005: Normal(Message, PopBNpc, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb204:66371 calling Scene00006: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb204:66371 calling [BranchTrue]Scene00007: Normal(Message, PopBNpc, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb204:66371 calling Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=FYRILSUNN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsb204 );
