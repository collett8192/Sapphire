// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: StmBdz311_02707
// Quest Name: The Two Princesses of SuinoSato
// Quest ID: 68243
// Start NPC: 1023280
// End NPC: 1023291

using namespace Sapphire;

class StmBdz311 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1023280;
//    static constexpr auto Actor1 = 1019197;
//    static constexpr auto Actor2 = 1023281;
//    static constexpr auto Actor3 = 1023291;
//    static constexpr auto Actor4 = 1023292;
//    static constexpr auto BindActor0 = 6958035;
//    static constexpr auto LocActor0 = 1022047;
//    static constexpr auto LocActor1 = 1022003;
//    static constexpr auto LocActor2 = 1022021;
//    static constexpr auto LocActor3 = 1022495;
//    static constexpr auto LocActor4 = 1022491;
//    static constexpr auto LocBgm0 = 458;
//    static constexpr auto LocBgm1 = 459;
//    static constexpr auto LocBgm2 = 484;
//    static constexpr auto LocBgm3 = 489;
//    static constexpr auto LocMotion0 = 4304;
//    static constexpr auto LocMotion1 = 85;
//    static constexpr auto LocMotion2 = 4296;
//    static constexpr auto LocMotion3 = 989;
//    static constexpr auto LocMotion4 = 586;
//    static constexpr auto LocMotion5 = 5473;
//    static constexpr auto LocMotion6 = 789;
//    static constexpr auto LocMotion7 = 3754;
//    static constexpr auto LocMotion8 = 4229;
//    static constexpr auto LocPos0 = 7013009;
//    static constexpr auto LocPos1 = 7015638;
//    static constexpr auto LocPos2 = 7021491;
//    static constexpr auto LocPos3 = 7021492;
//    static constexpr auto LocPos4 = 7021493;

  public:
    StmBdz311() : Sapphire::ScriptAPI::EventScript( 68243 ){}; 
    ~StmBdz311() = default; 

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

    player.playScene( getId(), 6, NONE, callback );
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
    };

    player.playScene( getId(), 8, NONE, callback );
  }

};

EXPOSE_SCRIPT( StmBdz311 );
