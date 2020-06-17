// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: StmBdi102_03004
// Quest Name: A City Fallen
// Quest ID: 68540
// Start NPC: 1024142
// End NPC: 1024149

using namespace Sapphire;

class StmBdi102 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      Seq2 = 2,
//      Seq3 = 3,
//      Seq4 = 4,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineStopCall = 4255;
//    static constexpr auto Actor0 = 1024142;
//    static constexpr auto Actor1 = 1024144;
//    static constexpr auto Actor10 = 1024148;
//    static constexpr auto Actor2 = 1024143;
//    static constexpr auto Actor3 = 5010000;
//    static constexpr auto Actor4 = 1024491;
//    static constexpr auto Actor5 = 1024146;
//    static constexpr auto Actor6 = 1024158;
//    static constexpr auto Actor7 = 1024159;
//    static constexpr auto Actor8 = 1024145;
//    static constexpr auto Actor9 = 1024149;
//    static constexpr auto Instancedungeon0 = 30058;
//    static constexpr auto LocAlma = 1023975;
//    static constexpr auto LocAlmaPos = 7128402;
//    static constexpr auto LocBgmBackgroundStory = 514;
//    static constexpr auto LocBgmHeroTheme = 512;
//    static constexpr auto LocCa001 = 1024326;
//    static constexpr auto LocCa002 = 1024327;
//    static constexpr auto LocCa003 = 1024328;
//    static constexpr auto LocCa004 = 1024329;
//    static constexpr auto LocCa005 = 1024330;
//    static constexpr auto LocHand = 5533;
//    static constexpr auto LocJakuemi = 6215;
//    static constexpr auto LocKanmu = 6216;
//    static constexpr auto LocKomaru = 625;
//    static constexpr auto LocObie3 = 4215;
//    static constexpr auto LocPanelOperation = 5540;
//    static constexpr auto LocPosDoor = 7132643;
//    static constexpr auto LocPosInt = 7101474;
//    static constexpr auto LocRamza = 1023976;
//    static constexpr auto LocRightTrun = 4256;
//    static constexpr auto LocRina = 1023978;
//    static constexpr auto LocSeDoorClose = 40;
//    static constexpr auto LocSeDoorOp = 39;
//    static constexpr auto LocSeMoveShip = 168;
//    static constexpr auto LocShizi = 816;
//    static constexpr auto LocSteering = 1024325;
//    static constexpr auto NcutStmbdi00021 = 1662;
//    static constexpr auto NcutStmbdi00030 = 1639;
//    static constexpr auto NcutStmbdi00040 = 1640;
//    static constexpr auto NcutStmbdi00050 = 1641;
//    static constexpr auto Poprange0 = 7130941;
//    static constexpr auto Poprange1 = 7143035;
//    static constexpr auto Poprange2 = 7146916;
//    static constexpr auto Poprange3 = 7080627;
//    static constexpr auto Territorytype0 = 735;
//    static constexpr auto UnlockImageDungeon = 546;

  public:
    StmBdi102() : Sapphire::ScriptAPI::EventScript( 68540 ){}; 
    ~StmBdi102() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player );
        break;
      }
      case 1:
      {
        Scene00002( player );
        break;
      }
      case 255:
      {
        Scene00017( player );
        break;
      }
    }
  }


  private:
  //////////////////////////////////////////////////////////////////////
  // Available Scenes in this quest, not necessarly all are used
  void Scene00000( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param2 == 1 )
        Scene00001( player );
    };

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 1 );
    };

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };

    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };

    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };

    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };

    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };

    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param2 == 1 )
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
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00019( player );
    };

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 20, NONE, callback );
  }

};

EXPOSE_SCRIPT( StmBdi102 );
