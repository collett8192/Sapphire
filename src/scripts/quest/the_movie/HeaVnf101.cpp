// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: HeaVnf101_02351
// Quest Name: Tidings from Gyr Abania
// Quest ID: 67887
// Start NPC: 1017788
// End NPC: 1013167

using namespace Sapphire;

class HeaVnf101 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1017788;
//    static constexpr auto Actor1 = 1013167;
//    static constexpr auto Actor2 = 1018037;
//    static constexpr auto Actor3 = 1018038;
//    static constexpr auto Actor4 = 1009220;
//    static constexpr auto Actor5 = 1006988;
//    static constexpr auto CutSceneN01 = 1297;
//    static constexpr auto Eobject0 = 2007563;
//    static constexpr auto Eventaction0 = 12;
//    static constexpr auto EventActionTimelineEmoteSalute = 725;
//    static constexpr auto FacialSpewing = 617;
//    static constexpr auto LcutSe0 = 95;
//    static constexpr auto LocAction0 = 1043;
//    static constexpr auto LocAction1 = 936;
//    static constexpr auto LocAction2 = 4229;
//    static constexpr auto LocActor0 = 1009751;
//    static constexpr auto LocActor1 = 1014558;
//    static constexpr auto LocActor2 = 1012189;
//    static constexpr auto LocActor3 = 1018387;
//    static constexpr auto LocActor4 = 1018388;
//    static constexpr auto LocActor5 = 1018389;
//    static constexpr auto LocActor6 = 1008178;
//    static constexpr auto LocActor7 = 1018390;
//    static constexpr auto LocBgm0 = 101;
//    static constexpr auto LocFace0 = 607;
//    static constexpr auto LocFace1 = 608;
//    static constexpr auto LocFace3 = 622;
//    static constexpr auto LocFace4 = 614;
//    static constexpr auto LocSe1 = 72;
//    static constexpr auto LocSe2 = 94;
//    static constexpr auto LocSe3 = 90;
//    static constexpr auto LocSe4 = 80;
//    static constexpr auto LocSe5 = 39;
//    static constexpr auto Poprange0 = 6526732;
//    static constexpr auto Poprange1 = 6728836;

  public:
    HeaVnf101() : Sapphire::ScriptAPI::EventScript( 67887 ){}; 
    ~HeaVnf101() = default; 

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
        Scene00003( player );
        break;
      }
      case 255:
      {
        Scene00007( player );
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
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
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

    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
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

};

EXPOSE_SCRIPT( HeaVnf101 );
