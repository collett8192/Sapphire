// FFXIVTheMovie.ParserV3
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea111 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea111() : Sapphire::ScriptAPI::EventScript( 65944 ){}; 
  ~SubSea111() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 6 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002232
  //ACTOR1 = 1002234
  //ACTOR2 = 1002235
  //EOBJECT0 = 2000760
  //EOBJECT1 = 2000764
  //EOBJECT2 = 2000765
  //EOBJECT3 = 2000761
  //EVENTACTIONPROCESSSHOR = 15
  //SEQ0ACTOR0 = 0
  //SEQ1ACTOR1 = 1
  //SEQ1ACTOR2 = 2
  //SEQ1EOBJECT0 = 3
  //SEQ1EOBJECT0EVENTACTIONNO = 99
  //SEQ1EOBJECT0EVENTACTIONOK = 100
  //SEQ1EOBJECT1 = 4
  //SEQ1EOBJECT1EVENTACTIONNO = 97
  //SEQ1EOBJECT1EVENTACTIONOK = 98
  //SEQ1EOBJECT2 = 5
  //SEQ1EOBJECT2EVENTACTIONNO = 95
  //SEQ1EOBJECT2EVENTACTIONOK = 96
  //SEQ1EOBJECT3 = 6
  //SEQ1EOBJECT3EVENTACTIONNO = 93
  //SEQ1EOBJECT3EVENTACTIONOK = 94
  //SEQ2ACTOR0 = 7

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=YULGIHONALGI
        break;
      }
      case 1:
      {
        if( actor == 1002234 || actorId == 1002234 ) // ACTOR1 = RAZYNMOLZYN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00001( player ); // Scene00001: Normal(Talk, TargetCanMove), id=RAZYNMOLZYN
          }
        }
        if( actor == 1002235 || actorId == 1002235 ) // ACTOR2 = RUIMOFALAIMO
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=RUIMOFALAIMO
          }
        }
        if( actor == 2000760 || actorId == 2000760 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 3 )
          {
            player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 2000764 || actorId == 2000764 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 3 )
          {
            player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 2000765 || actorId == 2000765 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 3 )
          {
            player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 2000761 || actorId == 2000761 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            player.setQuestUI8CH( getId(), 1 );
            checkProgressSeq1( player );
          }
        }
        break;
      }
      case 255:
      {
        Scene00007( player ); // Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YULGIHONALGI
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
        if( player.getQuestUI8BL( getId() ) == 3 )
          if( player.getQuestUI8BL( getId() ) == 3 )
            if( player.getQuestUI8BL( getId() ) == 3 )
              if( player.getQuestUI8CH( getId() ) == 1 )
              {
                player.setQuestUI8AL( getId(), 0 );
                player.setQuestUI8BH( getId(), 0 );
                player.setQuestUI8BL( getId(), 0 );
                player.setQuestUI8BL( getId(), 0 );
                player.setQuestUI8BL( getId(), 0 );
                player.setQuestUI8CH( getId(), 0 );
                player.updateQuest( getId(), 255 );
              }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubSea111:65944 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=YULGIHONALGI" );
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
    player.sendDebug( "SubSea111:65944 calling Scene00001: Normal(Talk, TargetCanMove), id=RAZYNMOLZYN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubSea111:65944 calling Scene00002: Normal(Talk, TargetCanMove), id=RUIMOFALAIMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubSea111:65944 calling Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YULGIHONALGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubSea111 );
