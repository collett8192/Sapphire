// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda702 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda702() : Sapphire::ScriptAPI::EventScript( 68085 ){}; 
  ~StmBda702() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 9 entries
  //SEQ_2, 1 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1021704
  //ACTOR1 = 1021705
  //ACTOR10 = 1021711
  //ACTOR11 = 1022730
  //ACTOR12 = 1022731
  //ACTOR2 = 1021706
  //ACTOR3 = 1022724
  //ACTOR4 = 1022725
  //ACTOR5 = 1022726
  //ACTOR6 = 1021708
  //ACTOR7 = 1022729
  //ACTOR8 = 1021710
  //ACTOR9 = 1021709
  //BINDACTOR01 = 6870611
  //BINDACTOR02 = 6870612
  //BINDACTOR03 = 6925935
  //BINDACTOR04 = 6925958
  //BINDACTOR05 = 6870672
  //EOBJECT0 = 2008283
  //LOCACTOR01 = 1015842
  //LOCACTOR02 = 1021992
  //LOCACTOR03 = 1022483
  //LOCACTOR04 = 1011887
  //LOCACTOR05 = 1019559
  //LOCIDLE01 = 808
  //LOCSE01 = 39
  //LOCSE02 = 40
  //QUESTBATTLE0 = 158
  //TERRITORYTYPE0 = 686
  //TERRITORYTYPE1 = 621

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1021704 || param2 == 1021704 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021705 || param2 == 1021705 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021706 || param2 == 1021706 ) // ACTOR2 = ARENVALD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022724 || param2 == 1022724 ) // ACTOR3 = MNAAGO
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022725 || param2 == 1022725 ) // ACTOR4 = VMAHTIA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022726 || param2 == 1022726 ) // ACTOR5 = JMOLDVA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1021705 || param2 == 1021705 ) // ACTOR1 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel), id=LYSE
          }
          break;
        }
        if( param1 == 2008283 || param2 == 2008283 ) // EOBJECT0 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 1021704 || param2 == 1021704 ) // ACTOR0 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021706 || param2 == 1021706 ) // ACTOR2 = ARENVALD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022724 || param2 == 1022724 ) // ACTOR3 = MNAAGO
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022725 || param2 == 1022725 ) // ACTOR4 = VMAHTIA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022726 || param2 == 1022726 ) // ACTOR5 = JMOLDVA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        if( param1 == 1021708 || param2 == 1021708 ) // ACTOR6 = THANCRED
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022729 || param2 == 1022729 ) // ACTOR7 = WISCAR
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00016( player ); // Scene00016: Normal(Talk, FadeIn, Dismount), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1021710 || param2 == 1021710 ) // ACTOR8 = LYSE
        {
          Scene00017( player ); // Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021709 || param2 == 1021709 ) // ACTOR9 = ALPHINAUD
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021711 || param2 == 1021711 ) // ACTOR10 = THANCRED
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022730 || param2 == 1022730 ) // ACTOR11 = WISCAR
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1022731 || param2 == 1022731 ) // ACTOR12 = WATT
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=WATT
          break;
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
    player.sendDebug( "StmBda702:68085 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda702:68085 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00003: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00004: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00005: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00006: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00007: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
        //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
        //player.eventFinish( getId(), 1 );
        //player.forceZoneing();
        Scene00016( player );
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00008: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00010: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00011: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00012: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00013: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00014: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00015: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00016: Normal(Talk, FadeIn, Dismount), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 621, 68.5, 45.411, 770, -1.86, false );
    };
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
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
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00018: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00019: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00020: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda702:68085 calling Scene00021: Normal(Talk, TargetCanMove), id=WATT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda702 );
