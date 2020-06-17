// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: LucKha002_03760
// Quest Name: The Mendicant's Court
// Quest ID: 69296
// Start NPC: 1031684
// End NPC: 1031684

using namespace Sapphire;

class LucKha002 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1031684;
//    static constexpr auto LevelEnpcId0 = 8144719;
//    static constexpr auto LocActor0 = 1031688;
//    static constexpr auto LocEnpcId0 = 1031681;
//    static constexpr auto LocEnpcId1 = 1032472;
//    static constexpr auto LocEnpcId2 = 1032473;
//    static constexpr auto LocEnpcId3 = 1032476;
//    static constexpr auto LocMotion0 = 1072;

  public:
    LucKha002() : Sapphire::ScriptAPI::EventScript( 69296 ){}; 
    ~LucKha002() = default; 

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

EXPOSE_SCRIPT( LucKha002 );
