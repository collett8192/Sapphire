// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: LucKhz102_03840
// Quest Name: Small Hands, Big Hearts
// Quest ID: 69376
// Start NPC: 1032813
// End NPC: 1032814

using namespace Sapphire;

class LucKhz102 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestUI8AL
    // GetQuestUI8BH

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
//    static constexpr auto Actor0 = 1032813;
//    static constexpr auto Actor1 = 1032816;
//    static constexpr auto Actor2 = 1032819;
//    static constexpr auto Actor3 = 1032814;
//    static constexpr auto Actor4 = 1032815;
//    static constexpr auto BindActor0 = 8267169;
//    static constexpr auto BindActor1 = 8267170;
//    static constexpr auto BindActor2 = 8267171;
//    static constexpr auto Item0 = 2002976;
//    static constexpr auto LocAction0 = 4301;
//    static constexpr auto LocActor0 = 1032968;
//    static constexpr auto LocActor1 = 1032969;
//    static constexpr auto LocActor2 = 1032970;
//    static constexpr auto LocActor3 = 1032769;
//    static constexpr auto LocActor4 = 1032770;
//    static constexpr auto LocActor5 = 1032771;
//    static constexpr auto LocActor6 = 1012455;
//    static constexpr auto LocBgm0 = 105;
//    static constexpr auto LocEnpc0 = 1033519;
//    static constexpr auto LocEnpc1 = 1033520;
//    static constexpr auto LocEnpc2 = 1033524;
//    static constexpr auto LocEnpc3 = 1033525;
//    static constexpr auto LocEobj0 = 2011037;
//    static constexpr auto LocEobj1 = 2011038;
//    static constexpr auto LocPosActor0 = 8307122;
//    static constexpr auto LocPosActor1 = 8307123;
//    static constexpr auto LocPosActor2 = 8307124;
//    static constexpr auto LocSe0 = 189;
//    static constexpr auto LocSe1 = 215;
//    static constexpr auto LocSe2 = 111;
//    static constexpr auto Poprange0 = 8343463;
//    static constexpr auto QstCompflag0 = 67642;

  public:
    LucKhz102() : Sapphire::ScriptAPI::EventScript( 69376 ){}; 
    ~LucKhz102() = default; 

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

};

EXPOSE_SCRIPT( LucKhz102 );
