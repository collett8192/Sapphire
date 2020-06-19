// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse615_00427
// Quest Name: The Parting Glass
// Quest ID: 65963
// Start NPC: 1001353
// End NPC: 1006384

using namespace Sapphire;

class GaiUse615 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1001353;
//    static constexpr auto Actor1 = 1010997;
//    static constexpr auto Actor2 = 1001821;
//    static constexpr auto Actor3 = 1010998;
//    static constexpr auto Actor4 = 1011622;
//    static constexpr auto Actor5 = 1006384;
//    static constexpr auto Actor6 = 1010928;
//    static constexpr auto Actor7 = 1006401;
//    static constexpr auto CutSceneN01 = 713;
//    static constexpr auto CutSceneN02 = 714;
//    static constexpr auto CutSceneN03 = 715;
//    static constexpr auto CutSceneN04 = 716;
//    static constexpr auto CutSceneN05 = 717;
//    static constexpr auto CutSceneN06 = 718;
//    static constexpr auto CutSceneN07 = 719;
//    static constexpr auto CutSceneN08 = 720;
//    static constexpr auto CutSceneN09 = 721;
//    static constexpr auto CutSceneN10 = 722;
//    static constexpr auto CutSceneN11 = 723;
//    static constexpr auto CutSceneN12 = 724;
//    static constexpr auto CutSceneN13 = 783;
//    static constexpr auto CutSceneN14 = 725;
//    static constexpr auto CutSceneN15 = 726;
//    static constexpr auto CutSceneN16 = 727;
//    static constexpr auto CutSceneN17 = 728;
//    static constexpr auto CutSceneN18 = 729;
//    static constexpr auto CutSceneN19 = 750;
//    static constexpr auto CutSceneN20 = 751;
//    static constexpr auto CutSceneN21 = 752;
//    static constexpr auto CutSceneN22 = 784;
//    static constexpr auto LocActor0 = 5608520;
//    static constexpr auto LocActor1 = 1003855;
//    static constexpr auto LocBgm0 = 211;
//    static constexpr auto Poprange0 = 5608625;
//    static constexpr auto Poprange1 = 5608535;

  public:
    GaiUse615() : Sapphire::ScriptAPI::EventScript( 65963 ){}; 
    ~GaiUse615() = default; 

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
        Scene00003( player );
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

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
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

    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };

    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };

    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
      if( result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
    };

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 12, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse615 );
