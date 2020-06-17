// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: LucKha102_03726
// Quest Name: Overseer for a Day
// Quest ID: 69262
// Start NPC: 1031991
// End NPC: 1032832

using namespace Sapphire;

class LucKha102 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1031991;
//    static constexpr auto Actor1 = 1032832;
//    static constexpr auto LevelEnpcId0 = 8268048;
//    static constexpr auto LocActor0 = 1031688;
//    static constexpr auto LocActor1 = 1032834;
//    static constexpr auto LocActor2 = 1032015;
//    static constexpr auto LocActor3 = 1032835;
//    static constexpr auto LocActor4 = 1032836;
//    static constexpr auto LocActor5 = 1011895;
//    static constexpr auto LocActor6 = 1007675;
//    static constexpr auto LocActor7 = 1032011;
//    static constexpr auto LocBgm0 = 105;
//    static constexpr auto LocEnpcId0 = 1031681;
//    static constexpr auto LocEnpcId1 = 1033444;
//    static constexpr auto LocEnpcId2 = 1033445;
//    static constexpr auto LocEnpcId3 = 1033446;
//    static constexpr auto LocEnpcId4 = 1033447;
//    static constexpr auto LocEnpcId5 = 1033448;
//    static constexpr auto LocEnpcId6 = 1033449;
//    static constexpr auto LocEnpcId7 = 1033450;
//    static constexpr auto LocEnpcId8 = 1033451;
//    static constexpr auto LocEnpcId9 = 1033452;
//    static constexpr auto LocMotion0 = 1072;
//    static constexpr auto Quest0 = 67861;
//    static constexpr auto Quest1 = 68441;

  public:
    LucKha102() : Sapphire::ScriptAPI::EventScript( 69262 ){}; 
    ~LucKha102() = default; 

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
        Scene00006( player );
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

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
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

    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( LucKha102 );
