// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: HeaVny806_02106
// Quest Name: Leves of Ishgard
// Quest ID: 67642
// Start NPC: 1011208
// End NPC: 1011208

using namespace Sapphire;

class HeaVny806 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1011208;
//    static constexpr auto QstHeavna103 = 67118;
//    static constexpr auto QstSubfst070 = 65756;
//    static constexpr auto QstSubsea901 = 66229;
//    static constexpr auto QstSubwil150 = 66223;
//    static constexpr auto Screenimage0 = 335;

  public:
    HeaVny806() : Sapphire::ScriptAPI::EventScript( 67642 ){}; 
    ~HeaVny806() = default; 

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

    player.playScene( getId(), 0, NONE, callback );
  }

};

EXPOSE_SCRIPT( HeaVny806 );
