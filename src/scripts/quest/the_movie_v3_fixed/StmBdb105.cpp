// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdb105 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdb105() : Sapphire::ScriptAPI::EventScript( 68502 ){}; 
  ~StmBdb105() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 1 entries
  //SEQ_2, 7 entries
  //SEQ_3, 9 entries
  //SEQ_4, 7 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1024125
  //ACTOR1 = 1024126
  //ACTOR10 = 1020555
  //ACTOR11 = 1024119
  //ACTOR12 = 1024120
  //ACTOR13 = 1024121
  //ACTOR2 = 1024127
  //ACTOR3 = 1024113
  //ACTOR4 = 1024114
  //ACTOR5 = 1024115
  //ACTOR6 = 1024116
  //ACTOR7 = 1024117
  //ACTOR8 = 1024118
  //ACTOR9 = 1020517
  //BINDACTOR0 = 7074670
  //BINDACTOR1 = 7074676
  //BINDACTOR2 = 7075127
  //BINDACTOR3 = 7074686
  //BINDACTOR4 = 7080993
  //BINDACTOR5 = 7081697
  //BINDACTOR6 = 7080995
  //BINDACTOR7 = 7081697
  //EOBJECT0 = 2009058
  //EOBJECT1 = 2009059
  //EVENTACTION0 = 54
  //EVENTACTION1 = 1
  //LOCACTOR0 = 1021968
  //LOCACTOR1 = 1011887
  //LOCACTOR2 = 1019537
  //LOCACTOR3 = 1019559
  //LOCBGM01 = 495
  //POPRANGE0 = 7080999
  //POPRANGE1 = 7074693
  //TERRITORYTYPE0 = 738

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1024125 || param2 == 1024125 ) // ACTOR0 = LYSE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1024126 || param2 == 1024126 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024127 || param2 == 1024127 ) // ACTOR2 = ARENVALD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        break;
      }
      case 1:
      {
        Scene00004( player ); // Scene00004: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESONATORIUMGUARD
        break;
      }
      case 2:
      {
        if( param1 == 1024114 || param2 == 1024114 ) // ACTOR4 = RAUBAHN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1024113 || param2 == 1024113 ) // ACTOR3 = RESONATORIUMGUARD
        {
          Scene00006( player ); // Scene00006: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESONATORIUMGUARD
          break;
        }
        if( param1 == 1024115 || param2 == 1024115 ) // ACTOR5 = LYSE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1024116 || param2 == 1024116 ) // ACTOR6 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024117 || param2 == 1024117 ) // ACTOR7 = ARENVALD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1024118 || param2 == 1024118 ) // ACTOR8 = FLAMEDOCTOR
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=FLAMEDOCTOR
          break;
        }
        if( param1 == 1020517 || param2 == 1020517 ) // ACTOR9 = IRONWORKSENGINEER
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=IRONWORKSENGINEER
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 2009058 || param2 == 2009058 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1024118 || param2 == 1024118 ) // ACTOR8 = FLAMEDOCTOR
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=FLAMEDOCTOR
            // +Callback Scene00015: Normal(Talk, TargetCanMove), id=FLAMEDOCTOR
          }
          break;
        }
        if( param1 == 1024113 || param2 == 1024113 ) // ACTOR3 = RESONATORIUMGUARD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESONATORIUMGUARD
          break;
        }
        if( param1 == 2009059 || param2 == 2009059 ) // EOBJECT1 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 1020517 || param2 == 1020517 ) // ACTOR9 = IRONWORKSENGINEER
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=IRONWORKSENGINEER
          break;
        }
        if( param1 == 1020555 || param2 == 1020555 ) // ACTOR10 = LYSE
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1024114 || param2 == 1024114 ) // ACTOR4 = RAUBAHN
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1024116 || param2 == 1024116 ) // ACTOR6 = ALPHINAUD
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024117 || param2 == 1024117 ) // ACTOR7 = ARENVALD
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1024114 || param2 == 1024114 ) // ACTOR4 = RAUBAHN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1024113 || param2 == 1024113 ) // ACTOR3 = RESONATORIUMGUARD
        {
          Scene00025( player ); // Scene00025: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESONATORIUMGUARD
          break;
        }
        if( param1 == 1024116 || param2 == 1024116 ) // ACTOR6 = ALPHINAUD
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024117 || param2 == 1024117 ) // ACTOR7 = ARENVALD
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1024118 || param2 == 1024118 ) // ACTOR8 = FLAMEDOCTOR
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=FLAMEDOCTOR
          break;
        }
        if( param1 == 1020517 || param2 == 1020517 ) // ACTOR9 = IRONWORKSENGINEER
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=IRONWORKSENGINEER
          break;
        }
        if( param1 == 1020555 || param2 == 1020555 ) // ACTOR10 = LYSE
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1024119 || param2 == 1024119 ) // ACTOR11 = LYSE
        {
          Scene00031( player ); // Scene00031: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1024120 || param2 == 1024120 ) // ACTOR12 = ALPHINAUD
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024121 || param2 == 1024121 ) // ACTOR13 = ARENVALD
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=ARENVALD
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.updateQuest( getId(), 4 );
      }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdb105:68502 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00003: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00004: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESONATORIUMGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        checkProgressSeq1( player );
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 738 );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00005: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00006: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESONATORIUMGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 738 );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00007: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00009: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00010: Normal(Talk, TargetCanMove), id=FLAMEDOCTOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00011: Normal(Talk, TargetCanMove), id=IRONWORKSENGINEER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00013: Normal(Talk, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00014: Normal(Talk, TargetCanMove), id=FLAMEDOCTOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00015: Normal(Talk, TargetCanMove), id=FLAMEDOCTOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00016: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESONATORIUMGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 738 );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00018: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00019: Normal(Talk, TargetCanMove), id=IRONWORKSENGINEER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00020: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00021: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00023: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00024: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      //player.forceZoneing();
      player.exitInstance();
    };
    player.playScene( getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00025: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESONATORIUMGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 738 );
      }
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00026: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00027: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00028: Normal(Talk, TargetCanMove), id=FLAMEDOCTOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00029: Normal(Talk, TargetCanMove), id=IRONWORKSENGINEER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00030: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00031: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
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
    player.playScene( getId(), 31, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBdb105:68502 calling Scene00033: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdb105 );
