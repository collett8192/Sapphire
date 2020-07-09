// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnf105 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnf105() : Sapphire::ScriptAPI::EventScript( 67891 ){}; 
  ~HeaVnf105() = default; 

  //SEQ_0, 6 entries
  //SEQ_255, 8 entries

  //ACTOR0 = 1018029
  //ACTOR1 = 1018026
  //ACTOR2 = 1018027
  //ACTOR3 = 1018028
  //ACTOR4 = 1018030
  //ACTOR5 = 1018031
  //ACTOR6 = 1018033
  //ACTOR7 = 1018034
  //LOCACTION0 = 1022
  //LOCACTION1 = 957
  //LOCACTOR0 = 1011887
  //LOCACTOR1 = 1011889
  //LOCACTOR2 = 1015833
  //LOCACTOR3 = 1008180
  //LOCACTOR4 = 1012189
  //LOCBGM0 = 211

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1018029 || param2 == 1018029 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1018026 || param2 == 1018026 ) // ACTOR1 = YDA
        {
          Scene00002( player ); // Scene00002: Normal(Talk), id=YDA
        }
        if( param1 == 1018027 || param2 == 1018027 ) // ACTOR2 = HILDA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1018028 || param2 == 1018028 ) // ACTOR3 = PIPIN
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=PIPIN
        }
        if( param1 == 1018030 || param2 == 1018030 ) // ACTOR4 = YUGIRI
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1018031 || param2 == 1018031 ) // ACTOR5 = THANCRED
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=THANCRED
        }
        break;
      }
      case 255:
      {
        if( param1 == 1018033 || param2 == 1018033 ) // ACTOR6 = ALISAIE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1018034 || param2 == 1018034 ) // ACTOR7 = TATARU
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1018026 || param2 == 1018026 ) // ACTOR1 = YDA
        {
          Scene00009( player ); // Scene00009: Normal(Talk), id=YDA
        }
        if( param1 == 1018027 || param2 == 1018027 ) // ACTOR2 = HILDA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1018028 || param2 == 1018028 ) // ACTOR3 = PIPIN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=PIPIN
        }
        if( param1 == 1018029 || param2 == 1018029 ) // ACTOR0 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1018030 || param2 == 1018030 ) // ACTOR4 = YUGIRI
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1018031 || param2 == 1018031 ) // ACTOR5 = THANCRED
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=THANCRED
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf105:67891 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnf105:67891 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf105:67891 calling Scene00002: Normal(Talk), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf105:67891 calling Scene00003: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf105:67891 calling Scene00004: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf105:67891 calling Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf105:67891 calling Scene00006: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf105:67891 calling Scene00007: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
          player.eventFinish( getId(), 1 );
          player.forceZoneing();
        }
      }
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf105:67891 calling Scene00008: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf105:67891 calling Scene00009: Normal(Talk), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf105:67891 calling Scene00010: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf105:67891 calling Scene00011: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf105:67891 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf105:67891 calling Scene00013: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf105:67891 calling Scene00014: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnf105 );
