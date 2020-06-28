// FFXIVTheMovie.ParserV3
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea059 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea059() : Sapphire::ScriptAPI::EventScript( 66007 ){}; 
  ~SubSea059() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 6 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002633
  //EOBJECT0 = 2001272
  //EOBJECT1 = 2001243
  //EOBJECT2 = 2001244
  //EOBJECT3 = 2001245
  //EOBJECT4 = 2001246
  //EOBJECT5 = 2001247
  //EOBJECT6 = 2001248
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONSEARCHSHORT = 2
  //ITEM0 = 2000350

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=GRYNEWYDA
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        // empty entry
        break;
      }
      //seq 2 event item ITEM0 = UI8BL max stack ?
      case 2:
      {
        if( actor == 2001243 || actorId == 2001243 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
            checkProgressSeq2( player );
          }
        }
        if( actor == 2001244 || actorId == 2001244 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
            checkProgressSeq2( player );
          }
        }
        if( actor == 2001245 || actorId == 2001245 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
            checkProgressSeq2( player );
          }
        }
        if( actor == 2001246 || actorId == 2001246 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq2( player );
          }
        }
        if( actor == 2001247 || actorId == 2001247 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq2( player );
          }
        }
        if( actor == 2001248 || actorId == 2001248 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq2( player );
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      case 255:
      {
        Scene00008( player ); // Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GRYNEWYDA
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 3 )
      if( player.getQuestUI8BH( getId() ) == 3 )
        if( player.getQuestUI8BH( getId() ) == 3 )
          if( player.getQuestUI8AL( getId() ) == 3 )
            if( player.getQuestUI8AL( getId() ) == 3 )
              if( player.getQuestUI8AL( getId() ) == 3 )
              {
                player.setQuestUI8BH( getId(), 0 );
                player.setQuestUI8BH( getId(), 0 );
                player.setQuestUI8BH( getId(), 0 );
                player.setQuestUI8AL( getId(), 0 );
                player.setQuestUI8AL( getId(), 0 );
                player.setQuestUI8AL( getId(), 0 );
                player.setQuestUI8BL( getId(), 0 );
                player.updateQuest( getId(), 255 );
              }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubSea059:66007 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=GRYNEWYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubSea059:66007 calling Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GRYNEWYDA" );
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

EXPOSE_SCRIPT( SubSea059 );
