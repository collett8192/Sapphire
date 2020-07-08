// FFXIVTheMovie.ParserV3
//fix: skip dungeon
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnc102 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnc102() : Sapphire::ScriptAPI::EventScript( 67768 ){}; 
  ~HeaVnc102() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 4 entries
  //SEQ_2, 1 entries
  //SEQ_3, 5 entries
  //SEQ_4, 1 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1016534
  //ACTOR1 = 1016535
  //ACTOR10 = 1016563
  //ACTOR2 = 1016558
  //ACTOR3 = 1015987
  //ACTOR4 = 1016559
  //ACTOR5 = 1012138
  //ACTOR6 = 5010000
  //ACTOR7 = 1016560
  //ACTOR8 = 1016561
  //ACTOR9 = 1016562
  //CUTSCENEN01 = 1141
  //CUTSCENEN02 = 1142
  //CUTSCENEN03 = 1143
  //INSTANCEDUNGEON0 = 43
  //LOCACTOR0 = 6184223
  //LOCACTOR10 = 1011887
  //LOCACTOR11 = 6080649
  //LOCACTOR12 = 6184373
  //LOCACTOR20 = 1011889
  //LOCACTOR21 = 1015842
  //LOCACTOR22 = 1015833
  //LOCFACIAL0 = 607
  //LOCSCREENIMAGE0 = 371
  //POPRANGE0 = 6184541
  //TERRITORYTYPE0 = 463

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1016534 || param2 == 1016534 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1016535 || param2 == 1016535 ) // ACTOR1 = TATARU
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 1:
      {
        if( param1 == 1016558 || param2 == 1016558 ) // ACTOR2 = KRILE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=KRILE
          }
        }
        if( param1 == 1015987 || param2 == 1015987 ) // ACTOR3 = YSHTOLA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1016559 || param2 == 1016559 ) // ACTOR4 = THANCRED
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1016535 || param2 == 1016535 ) // ACTOR1 = TATARU
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 2:
      {
        Scene00007( player ); // Scene00007: Normal(Talk, Message, FadeIn, TargetCanMove), id=MATOYA
        break;
      }
      case 3:
      {
        if( param1 == 1016560 || param2 == 1016560 ) // ACTOR7 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1016561 || param2 == 1016561 ) // ACTOR8 = YSHTOLA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1016562 || param2 == 1016562 ) // ACTOR9 = THANCRED
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1016563 || param2 == 1016563 ) // ACTOR10 = KRILE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1012138 || param2 == 1012138 ) // ACTOR5 = MATOYA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=MATOYA
        }
        break;
      }
      case 4:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00013( player ); // Scene00013: Normal(CutScene), id=unknown
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016560 || param2 == 1016560 ) // ACTOR7 = ALPHINAUD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1012138 || param2 == 1012138 ) // ACTOR5 = MATOYA
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=MATOYA
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc102:67768 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnc102:67768 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc102:67768 calling Scene00002: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc102:67768 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc102:67768 calling Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc102:67768 calling Scene00005: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc102:67768 calling Scene00006: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc102:67768 calling Scene00007: Normal(Talk, Message, FadeIn, TargetCanMove), id=MATOYA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc102:67768 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc102:67768 calling Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc102:67768 calling Scene00010: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc102:67768 calling Scene00011: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc102:67768 calling Scene00012: Normal(Talk, TargetCanMove), id=MATOYA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc102:67768 calling Scene00013: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc102:67768 calling Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.sendDebug( "HeaVnc102:67768 calling Scene00015: Normal(Talk, TargetCanMove), id=MATOYA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnc102 );
