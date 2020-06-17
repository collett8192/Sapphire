// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: HeaVny211_02230
// Quest Name: When the Bough Wakes
// Quest ID: 67766
// Start NPC: 1014565
// End NPC: 1014565

using namespace Sapphire;

class HeaVny211 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineEmoteBow = 694;
//    static constexpr auto ActionTimelineEmoteGoodbye = 705;
//    static constexpr auto ActionTimelineEmoteMe = 715;
//    static constexpr auto ActionTimelineEmoteThink = 736;
//    static constexpr auto ActionTimelineEventFacial01 = 611;
//    static constexpr auto ActionTimelineEventFacial02 = 605;
//    static constexpr auto ActionTimelineEventPoint = 720;
//    static constexpr auto ActionTimelineEventThink = 669;
//    static constexpr auto Actor0 = 1014565;
//    static constexpr auto Actor1 = 1016631;
//    static constexpr auto Actor2 = 5010000;
//    static constexpr auto Actor3 = 1016633;
//    static constexpr auto ActEventLink = 1002;
//    static constexpr auto BindActor0 = 6211051;
//    static constexpr auto CutSceneN01 = 1164;
//    static constexpr auto Instancedungeon0 = 20037;
//    static constexpr auto Instancedungeon0 = 20037;
//    static constexpr auto LcutSe0 = 39;
//    static constexpr auto LcutSe1 = 40;
//    static constexpr auto LocActor0 = 1016632;
//    static constexpr auto LocActor1 = 1016634;
//    static constexpr auto LocActor2 = 1016760;
//    static constexpr auto LocActor3 = 1008180;
//    static constexpr auto LocActor4 = 1011889;
//    static constexpr auto LocActor5 = 1015833;
//    static constexpr auto LocActor6 = 1011863;
//    static constexpr auto LocMusic0 = 85;
//    static constexpr auto LocMusic1 = 114;
//    static constexpr auto LocMusic2 = 97;
//    static constexpr auto Poprange0 = 6250161;
//    static constexpr auto Poprange1 = 6215485;
//    static constexpr auto Screenimage0 = 377;
//    static constexpr auto Territorytype0 = 402;

  public:
    HeaVny211() : Sapphire::ScriptAPI::EventScript( 67766 ){}; 
    ~HeaVny211() = default; 

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
      case 255:
      {
        Scene00009( player );
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
      Scene00002( player );
    };

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
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

    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 10, NONE, callback );
  }

};

EXPOSE_SCRIPT( HeaVny211 );
