// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnc107 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnc107() : Sapphire::ScriptAPI::EventScript( 67773 ){}; 
  ~HeaVnc107() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 6 entries
  //SEQ_2, 5 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1016580
  //ACTOR1 = 1016578
  //ACTOR10 = 1016579
  //ACTOR11 = 1016582
  //ACTOR2 = 1016568
  //ACTOR3 = 1016569
  //ACTOR4 = 1016570
  //ACTOR5 = 1016069
  //ACTOR6 = 1016070
  //ACTOR7 = 1016581
  //ACTOR8 = 1016077
  //ACTOR9 = 1016071
  //CUTSCENEN01 = 1148
  //LOCACTOR0 = 1008193
  //LOCACTOR1 = 1011893
  //LOCACTOR2 = 1013876
  //LOCACTOR3 = 1015842
  //LOCIDLE0 = 804
  //LOCSE0 = 44

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1016580 || param2 == 1016580 ) // ACTOR0 = THANCRED
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=THANCRED
        }
        if( param1 == 1016578 || param2 == 1016578 ) // ACTOR1 = EMMANELLAIN
        {
          Scene00002( player ); // Scene00002: Normal(Talk), id=EMMANELLAIN
        }
        if( param1 == 1016568 || param2 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=CITIZENA02233
        }
        if( param1 == 1016569 || param2 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=CITIZENB02233
        }
        if( param1 == 1016570 || param2 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=CITIZENC02233
        }
        break;
      }
      case 1:
      {
        if( param1 == 1016069 || param2 == 1016069 ) // ACTOR5 = LUCIA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=LUCIA
          }
        }
        if( param1 == 1016578 || param2 == 1016578 ) // ACTOR1 = EMMANELLAIN
        {
          Scene00007( player ); // Scene00007: Normal(Talk), id=EMMANELLAIN
        }
        if( param1 == 1016568 || param2 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=CITIZENA02233
        }
        if( param1 == 1016569 || param2 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=CITIZENB02233
        }
        if( param1 == 1016570 || param2 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=CITIZENC02233
        }
        if( param1 == 1016070 || param2 == 1016070 ) // ACTOR6 = ARTOIREL
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ARTOIREL
        }
        break;
      }
      case 2:
      {
        if( param1 == 1016581 || param2 == 1016581 ) // ACTOR7 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1016077 || param2 == 1016077 ) // ACTOR8 = THANCRED
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1016069 || param2 == 1016069 ) // ACTOR5 = LUCIA
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1016070 || param2 == 1016070 ) // ACTOR6 = ARTOIREL
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ARTOIREL
        }
        if( param1 == 1016071 || param2 == 1016071 ) // ACTOR9 = EMMANELLAIN
        {
          Scene00016( player ); // Scene00016: Normal(Talk), id=EMMANELLAIN
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016579 || param2 == 1016579 ) // ACTOR10 = THANCRED
        {
          Scene00017( player ); // Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=THANCRED
        }
        if( param1 == 1016581 || param2 == 1016581 ) // ACTOR7 = HONOROIT
        {
          Scene00018( player ); // Scene00018: Normal(Talk), id=HONOROIT
        }
        if( param1 == 1016582 || param2 == 1016582 ) // ACTOR11 = EMMANELLAIN
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        if( param1 == 1016069 || param2 == 1016069 ) // ACTOR5 = LUCIA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1016070 || param2 == 1016070 ) // ACTOR6 = ARTOIREL
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ARTOIREL
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnc107:67773 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00002: Normal(Talk), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00003: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00004: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00005: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00007: Normal(Talk), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00008: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00009: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00010: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00011: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00012: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00013: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00014: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00015: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00016: Normal(Talk), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00018: Normal(Talk), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00019: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00020: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc107:67773 calling Scene00021: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnc107 );
