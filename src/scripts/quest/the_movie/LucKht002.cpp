// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: LucKht002_03849
// Quest Name: Work It Harder, Make It Better
// Quest ID: 69385
// Start NPC: 1032898
// End NPC: 1032899

using namespace Sapphire;

class LucKht002 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestUI8AL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1032898;
//    static constexpr auto Actor1 = 1032899;
//    static constexpr auto BindActor0 = 8274203;
//    static constexpr auto BindActor1 = 8274204;
//    static constexpr auto LocActor0 = 1032950;
//    static constexpr auto LocActor1 = 1032951;
//    static constexpr auto LocActor2 = 1032952;
//    static constexpr auto QstHeavny801 = 67631;
//    static constexpr auto Ritem0 = 29634;
//    static constexpr auto Ritem1 = 29635;
//    static constexpr auto Ritem2 = 29636;
//    static constexpr auto Ritem3 = 29637;
//    static constexpr auto Ritem4 = 29638;
//    static constexpr auto Ritem5 = 29639;
//    static constexpr auto Ritem6 = 29640;
//    static constexpr auto Ritem7 = 29641;
//    static constexpr auto Ritem8 = 29642;
//    static constexpr auto Ritem9 = 29643;
//    static constexpr auto RitemAdd10 = 29644;

  public:
    LucKht002() : Sapphire::ScriptAPI::EventScript( 69385 ){}; 
    ~LucKht002() = default; 

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
      player.updateQuest( getId(), 255 );
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
      if( result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
    };

    player.playScene( getId(), 3, NONE, callback );
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
    };

    player.playScene( getId(), 5, NONE, callback );
  }

};

EXPOSE_SCRIPT( LucKht002 );
