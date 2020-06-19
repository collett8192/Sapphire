// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: FesGsc301_03207
// Quest Name: The Sabotender Shimmy
// Quest ID: 68743
// Start NPC: 1028241
// End NPC: 1028243

using namespace Sapphire;

class FesGsc301 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1028241;
//    static constexpr auto Actor1 = 1028242;
//    static constexpr auto Actor2 = 1028243;
//    static constexpr auto LocActor0 = 1028244;
//    static constexpr auto LocActor1 = 1028245;
//    static constexpr auto LocActor2 = 1028246;
//    static constexpr auto LocActor3 = 1028247;
//    static constexpr auto LocActor4 = 1015922;
//    static constexpr auto LocActor5 = 1011586;
//    static constexpr auto LocActor6 = 1028248;
//    static constexpr auto LocActor7 = 1028249;
//    static constexpr auto LocBgm0 = 72;
//    static constexpr auto LocBgm1 = 105;
//    static constexpr auto LocEnpcId0 = 1009435;
//    static constexpr auto LocEnpcId1 = 1028250;
//    static constexpr auto LocEnpcId2 = 1011052;
//    static constexpr auto LocEnpcId3 = 1011053;
//    static constexpr auto LocEnpcId4 = 1011054;
//    static constexpr auto LocEnpcId5 = 1011092;
//    static constexpr auto LocMotion0 = 1089;
//    static constexpr auto LocMotion1 = 6250;
//    static constexpr auto LocMotion2 = 625;
//    static constexpr auto LocMotion3 = 6228;
//    static constexpr auto LocMotion4 = 5596;
//    static constexpr auto LocPosActor0 = 7845275;
//    static constexpr auto Quest0 = 65970;

  public:
    FesGsc301() : Sapphire::ScriptAPI::EventScript( 68743 ){}; 
    ~FesGsc301() = default; 

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

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
      if( result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
    };

    player.playScene( getId(), 6, NONE, callback );
  }

};

EXPOSE_SCRIPT( FesGsc301 );
