// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: StmBdy401_03078
// Quest Name: And We Shall Call It Eureka
// Quest ID: 68614
// Start NPC: 1019459
// End NPC: 1025233

using namespace Sapphire;

class StmBdy401 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1019459;
//    static constexpr auto Actor1 = 1019002;
//    static constexpr auto Actor2 = 1025233;
//    static constexpr auto Actor3 = 1025234;
//    static constexpr auto CutSceneN01 = 1748;
//    static constexpr auto LocActor01 = 1019084;
//    static constexpr auto LocActor02 = 1018496;
//    static constexpr auto LocActor03 = 1015833;
//    static constexpr auto LocActor04 = 1025200;
//    static constexpr auto LocActor05 = 1025201;
//    static constexpr auto LocActor06 = 1025202;
//    static constexpr auto LocActor07 = 1024485;
//    static constexpr auto LocIdle01 = 911;
//    static constexpr auto LocIdle02 = 855;
//    static constexpr auto LocIdle03 = 5493;
//    static constexpr auto LocIdle04 = 1065;
//    static constexpr auto LocItem01 = 13775;
//    static constexpr auto Poprange0 = 7317389;
//    static constexpr auto Quest01 = 66241;
//    static constexpr auto Quest02 = 67747;
//    static constexpr auto UnlockImageDungeon = 595;

  public:
    StmBdy401() : Sapphire::ScriptAPI::EventScript( 68614 ){}; 
    ~StmBdy401() = default; 

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
        Scene00005( player );
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
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
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

    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 6, NONE, callback );
  }

};

EXPOSE_SCRIPT( StmBdy401 );
