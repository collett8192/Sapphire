// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ClsWdk000_00138
// Quest Name: Way of the Carpenter
// Quest ID: 65674
// Start NPC: 1000148
// End NPC: 1000153

using namespace Sapphire;

class ClsWdk000 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto ActionTimelineEventReactionEleM = 774;
//    static constexpr auto Actor0 = 1000148;
//    static constexpr auto Actor1 = 1000153;
//    static constexpr auto Classjob = 8;
//    static constexpr auto GearsetUnlock = 1905;
//    static constexpr auto LogmessageCraftNotePageUnlock = 1187;
//    static constexpr auto Seq0Actor0 = 0;
//    static constexpr auto Seq1Actor1 = 1;
//    static constexpr auto UnlockImageClassWdk = 28;
//    static constexpr auto UnlockImageGearSet = 29;
//    static constexpr auto UnlockImageRecipeBook = 16;
//    static constexpr auto UnlockRecipeBook = 17;

  public:
    ClsWdk000() : Sapphire::ScriptAPI::EventScript( 65674 ){}; 
    ~ClsWdk000() = default; 

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
        Scene00001( player );
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
        player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
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

    player.playScene( getId(), 1, NONE, callback );
  }

};

EXPOSE_SCRIPT( ClsWdk000 );
