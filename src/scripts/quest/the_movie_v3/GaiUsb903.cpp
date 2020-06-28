// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb903 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb903() : Sapphire::ScriptAPI::EventScript( 66462 ){}; 
  ~GaiUsb903() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_2, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006447
  //ACTOR1 = 1006444
  //ENEMY0 = 4293210
  //ENEMY1 = 4293211
  //EOBJECT0 = 2002157
  //EOBJECT1 = 2002513
  //EVENTRANGE0 = 4293212
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000723

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=NIVIE
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( actor == 4293212 || actorId == 4293212 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00002( player ); // Scene00002: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 2002157 || actorId == 2002157 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00003( player ); // Scene00003: Normal(Message), id=unknown
            // +Callback Scene00004: Normal(None), id=unknown
          }
        }
        if( actor == 4293210 || actorId == 4293210 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4293211 || actorId == 4293211 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 2002513 || actorId == 2002513 ) // EOBJECT1 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          // +Callback Scene00006: Normal(None), id=unknown
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        Scene00007( player ); // Scene00007: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00008: Normal(Talk, TargetCanMove), id=DRILLEMONT
        break;
      }
      case 255:
      {
        Scene00009( player ); // Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=NIVIE
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
    if( player.getQuestUI8AL( getId() ) == 2 )
      if( player.getQuestUI8AL( getId() ) == 2 )
      {
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.updateQuest( getId(), 2 );
        player.setQuestUI8BH( getId(), 1 );
      }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb903:66462 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "GaiUsb903:66462 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=NIVIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb903:66462 calling Scene00002: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb903:66462 calling Scene00003: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb903:66462 calling [BranchTrue]Scene00004: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 2 );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb903:66462 calling Scene00005: Normal(None), id=unknown" );
    Scene00006( player );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb903:66462 calling [BranchTrue]Scene00006: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb903:66462 calling Scene00007: NpcTrade(Talk, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb903:66462 calling [BranchTrue]Scene00008: Normal(Talk, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb903:66462 calling Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=NIVIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsb903 );
