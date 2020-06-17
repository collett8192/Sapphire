// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ClsThm011_00344
// Quest Name: Way of the Thaumaturge
// Quest ID: 65880
// Start NPC: 1002279
// End NPC: 1001709

using namespace Sapphire;

class ClsThm011 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1002279;
//    static constexpr auto Actor1 = 1001709;
//    static constexpr auto Classjob = 7;
//    static constexpr auto GearsetUnlock = 1905;
//    static constexpr auto LocActor1 = 1001708;
//    static constexpr auto LocActor2 = 1001709;
//    static constexpr auto LocActor3 = 1001710;
//    static constexpr auto LocActor4 = 1001711;
//    static constexpr auto LocActor5 = 1001712;
//    static constexpr auto LocPosActor3 = 3996617;
//    static constexpr auto LocPosActor4 = 3996618;
//    static constexpr auto LocPosActor5 = 3996619;
//    static constexpr auto LogmessageMonsterNotePageUnlock = 1014;
//    static constexpr auto UnlockImageClassThm = 43;

  public:
    ClsThm011() : Sapphire::ScriptAPI::EventScript( 65880 ){}; 
    ~ClsThm011() = default; 

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
        Scene00002( player );
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
    };

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
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

    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( ClsThm011 );
