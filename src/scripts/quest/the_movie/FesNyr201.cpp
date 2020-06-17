// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: FesNyr201_02217
// Quest Name: Monkey about Town
// Quest ID: 67753
// Start NPC: 1016387
// End NPC: 1016387

using namespace Sapphire;

class FesNyr201 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
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
//    static constexpr auto Actor0 = 1016387;
//    static constexpr auto Actor1 = 5010000;
//    static constexpr auto Actor2 = 1016388;
//    static constexpr auto Fate0 = 936;
//    static constexpr auto Fate1 = 937;
//    static constexpr auto Fate2 = 938;
//    static constexpr auto Fate3 = 939;
//    static constexpr auto Fate4 = 940;
//    static constexpr auto Fate5 = 941;
//    static constexpr auto LevelEnpcId0 = 6148089;
//    static constexpr auto LevelEnpcId1 = 6148090;
//    static constexpr auto LocActor0 = 1016397;
//    static constexpr auto LocActor1 = 1016398;
//    static constexpr auto LocActor2 = 1016399;
//    static constexpr auto LocActor3 = 1016400;
//    static constexpr auto LocActor4 = 1016401;
//    static constexpr auto LocActor5 = 1016402;
//    static constexpr auto LocActor6 = 1016403;
//    static constexpr auto LocActor7 = 1016509;
//    static constexpr auto LocMotion0 = 796;
//    static constexpr auto LocMotion1 = 801;

  public:
    FesNyr201() : Sapphire::ScriptAPI::EventScript( 67753 ){}; 
    ~FesNyr201() = default; 

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
        Scene00004( player );
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

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
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

    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 5, NONE, callback );
  }

};

EXPOSE_SCRIPT( FesNyr201 );
