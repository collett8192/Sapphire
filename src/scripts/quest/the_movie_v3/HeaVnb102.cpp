// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnb102 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnb102() : Sapphire::ScriptAPI::EventScript( 67693 ){}; 
  ~HeaVnb102() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 2 entries
  //SEQ_2, 1 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1015979
  //ACTOR1 = 1015978
  //ACTOR2 = 1015980
  //ACTOR3 = 1015981
  //ACTOR4 = 1011935
  //ACTOR5 = 1015983
  //ACTOR6 = 1015982
  //LOCACTOR0 = 6080405
  //LOCACTOR1 = 6080545
  //LOCACTOR10 = 1011887
  //LOCACTOR11 = 1015889
  //LOCACTOR20 = 6080634
  //LOCBGM0 = 313

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1015979 || param2 == 1015979 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1015978 || param2 == 1015978 ) // ACTOR1 = LUCIA
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LUCIA
        }
        break;
      }
      case 1:
      {
        if( param1 == 1015980 || param2 == 1015980 ) // ACTOR2 = LUCIA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=LUCIA
          }
        }
        if( param1 == 1015981 || param2 == 1015981 ) // ACTOR3 = ALPHINAUD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 2:
      {
        Scene00005( player ); // Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=VIDOFNIR
        break;
      }
      case 255:
      {
        if( param1 == 1015983 || param2 == 1015983 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=unknown
        }
        if( param1 == 1015982 || param2 == 1015982 ) // ACTOR6 = LUCIA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1011935 || param2 == 1011935 ) // ACTOR4 = VIDOFNIR
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=VIDOFNIR
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
    onProgress( player, param1, param1, 3, 0 );
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb102:67693 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnb102:67693 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb102:67693 calling Scene00002: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb102:67693 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb102:67693 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb102:67693 calling Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=VIDOFNIR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb102:67693 calling Scene00006: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb102:67693 calling Scene00007: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb102:67693 calling Scene00008: Normal(Talk, TargetCanMove), id=VIDOFNIR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnb102 );
