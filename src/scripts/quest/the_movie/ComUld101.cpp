// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ComUld101_02391
// Quest Name: Squadron and Commander (Immortal Flames)
// Quest ID: 67927
// Start NPC: 1002391
// End NPC: 1002391

using namespace Sapphire;

class ComUld101 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1002391;
//    static constexpr auto Actor1 = 2469764;
//    static constexpr auto Actor2 = 5675650;
//    static constexpr auto LocActor0 = 1018175;
//    static constexpr auto LocActor1 = 1018176;
//    static constexpr auto LocActor2 = 1018177;
//    static constexpr auto LocActor3 = 1018178;
//    static constexpr auto LocActor4 = 1018179;
//    static constexpr auto LocActor5 = 1018180;
//    static constexpr auto UnlockImageGcTeam = 407;

  public:
    ComUld101() : Sapphire::ScriptAPI::EventScript( 67927 ){}; 
    ~ComUld101() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
    switch( player.getQuestSeq( getId() ) )
    {
    }
  }


  private:
  //////////////////////////////////////////////////////////////////////
  // Available Scenes in this quest, not necessarly all are used
  void Scene00000( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 0, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( ComUld101 );
