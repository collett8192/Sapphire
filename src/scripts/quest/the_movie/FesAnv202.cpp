// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: FesAnv202_02330
// Quest Name: The Show Must Go On
// Quest ID: 67866
// Start NPC: 1017488
// End NPC: 1017488

using namespace Sapphire;

class FesAnv202 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1017488;
//    static constexpr auto Actor1 = 1017521;
//    static constexpr auto LocAction1 = 1071;
//    static constexpr auto LocAction2 = 1022;
//    static constexpr auto LocAction5 = 934;
//    static constexpr auto LocAction6 = 4233;
//    static constexpr auto LocAction8 = 1050;
//    static constexpr auto LocActor11 = 1017507;
//    static constexpr auto LocActor12 = 1017492;
//    static constexpr auto LocActor9 = 1017506;
//    static constexpr auto LocArmor01 = 24;
//    static constexpr auto LocArmor02 = 25;
//    static constexpr auto LocArmor03 = 19;
//    static constexpr auto LocArmor04 = 20;
//    static constexpr auto LocArmor05 = 21;
//    static constexpr auto LocArmor06 = 22;
//    static constexpr auto LocArmor07 = 23;
//    static constexpr auto LocBgm01 = 89;
//    static constexpr auto LocBgm02 = 236;
//    static constexpr auto LocBgm04 = 61;
//    static constexpr auto LocPos1 = 6351609;
//    static constexpr auto LocPos2 = 6352323;
//    static constexpr auto LocSe5 = 48;
//    static constexpr auto LocVfx1 = 300;
//    static constexpr auto NcutEventFesanv2021 = 1231;
//    static constexpr auto NcutEventFesanv2022 = 1232;
//    static constexpr auto NcutEventFesanv2023 = 1233;
//    static constexpr auto QstCheck01 = 67866;
//    static constexpr auto QstCheck02 = 67867;

  public:
    FesAnv202() : Sapphire::ScriptAPI::EventScript( 67866 ){}; 
    ~FesAnv202() = default; 

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

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 6, NONE, callback );
  }

};

EXPOSE_SCRIPT( FesAnv202 );
