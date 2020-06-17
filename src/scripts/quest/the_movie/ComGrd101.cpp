// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ComGrd101_02389
// Quest Name: Squadron and Commander (Twin Adder)
// Quest ID: 67925
// Start NPC: 1002394
// End NPC: 1002394

using namespace Sapphire;

class ComGrd101 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1002394;
//    static constexpr auto LocActor0 = 1018163;
//    static constexpr auto LocActor1 = 1018164;
//    static constexpr auto LocActor2 = 1018165;
//    static constexpr auto LocActor3 = 1018166;
//    static constexpr auto LocActor4 = 1018167;
//    static constexpr auto LocActor5 = 1018168;
//    static constexpr auto LocActor6 = 1023971;
//    static constexpr auto LocActor7 = 1023972;
//    static constexpr auto LocActor8 = 1023973;
//    static constexpr auto LocActor9 = 1023974;
//    static constexpr auto LocLevelActor6 = 3975026;
//    static constexpr auto LocLevelActor7 = 3975027;
//    static constexpr auto LocLevelActor8 = 4058875;
//    static constexpr auto LocLevelActor9 = 4256731;
//    static constexpr auto UnlockImageGcTeam = 407;

  public:
    ComGrd101() : Sapphire::ScriptAPI::EventScript( 67925 ){}; 
    ~ComGrd101() = default; 

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

EXPOSE_SCRIPT( ComGrd101 );
