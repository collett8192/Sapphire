// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ManFst204 : public Sapphire::ScriptAPI::EventScript
{
public:
  ManFst204() : Sapphire::ScriptAPI::EventScript( 66213 ){}; 
  ~ManFst204() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 6 entries
  //SEQ_2, 6 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000100
  //ACTOR1 = 1004612
  //ACTOR2 = 1004619
  //ACTOR3 = 1004620
  //ACTOR4 = 1004613
  //ACTOR5 = 1004614
  //ACTOR6 = 1004615
  //INSTANCEDUNGEON0 = 2
  //LOCACTOR0 = 1003061
  //LOCACTOR1 = 1004616
  //LOCACTOR2 = 1004617
  //LOCACTOR3 = 1004618
  //LOCFACE0 = 604
  //LOCFACE1 = 617
  //LOCFACE2 = 612
  //LOCFACE3 = 605
  //LOCPOSACTOR3 = 4091288
  //SEQ0ACTOR0LQ = 90
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKIMAGEDUNGEONTAMTARA = 76

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MIOUNNE
        break;
      }
      case 1:
      {
        if( param1 == 1004612 || param2 == 1004612 ) // ACTOR1 = GODSQUIVERBOW
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, Message, TargetCanMove), id=GODSQUIVERBOW
          }
          break;
        }
        if( param1 == 1004619 || param2 == 1004619 ) // ACTOR2 = ISILDAURE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ISILDAURE
          break;
        }
        if( param1 == 1004620 || param2 == 1004620 ) // ACTOR3 = ALIANNE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALIANNE
          break;
        }
        if( param1 == 1004613 || param2 == 1004613 ) // ACTOR4 = DOLOROUSBEAR
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=DOLOROUSBEAR
          break;
        }
        if( param1 == 1004614 || param2 == 1004614 ) // ACTOR5 = EMANAFA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=EMANAFA
          break;
        }
        if( param1 == 1004615 || param2 == 1004615 ) // ACTOR6 = KIKINA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=KIKINA
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1004619 || param2 == 1004619 ) // ACTOR2 = ISILDAURE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ISILDAURE
          break;
        }
        if( param1 == 1004620 || param2 == 1004620 ) // ACTOR3 = ALIANNE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALIANNE
          break;
        }
        if( param1 == 1004613 || param2 == 1004613 ) // ACTOR4 = DOLOROUSBEAR
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=DOLOROUSBEAR
          break;
        }
        if( param1 == 1004614 || param2 == 1004614 ) // ACTOR5 = EMANAFA
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=EMANAFA
          break;
        }
        if( param1 == 1004615 || param2 == 1004615 ) // ACTOR6 = KIKINA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=KIKINA
          break;
        }
        if( param1 == 1004612 || param2 == 1004612 ) // ACTOR1 = GODSQUIVERBOW
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=GODSQUIVERBOW
          break;
        }
        break;
      }
      case 255:
      {
        Scene00014( player ); // Scene00014: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=MIOUNNE
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
    player.sendDebug( "ManFst204:66213 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "ManFst204:66213 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MIOUNNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "ManFst204:66213 calling Scene00002: Normal(Talk, Message, TargetCanMove), id=GODSQUIVERBOW" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "ManFst204:66213 calling Scene00003: Normal(Talk, TargetCanMove), id=ISILDAURE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "ManFst204:66213 calling Scene00004: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "ManFst204:66213 calling Scene00005: Normal(Talk, TargetCanMove), id=DOLOROUSBEAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "ManFst204:66213 calling Scene00006: Normal(Talk, TargetCanMove), id=EMANAFA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "ManFst204:66213 calling Scene00007: Normal(Talk, TargetCanMove), id=KIKINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "ManFst204:66213 calling Scene00008: Normal(Talk, TargetCanMove), id=ISILDAURE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "ManFst204:66213 calling Scene00009: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "ManFst204:66213 calling Scene00010: Normal(Talk, TargetCanMove), id=DOLOROUSBEAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "ManFst204:66213 calling Scene00011: Normal(Talk, TargetCanMove), id=EMANAFA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "ManFst204:66213 calling Scene00012: Normal(Talk, TargetCanMove), id=KIKINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "ManFst204:66213 calling Scene00013: Normal(Talk, TargetCanMove), id=GODSQUIVERBOW" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "ManFst204:66213 calling Scene00014: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=MIOUNNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( ManFst204 );
