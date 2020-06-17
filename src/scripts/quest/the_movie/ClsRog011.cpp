// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ClsRog011_00102
// Quest Name: My First Daggers
// Quest ID: 65638
// Start NPC: 1009944
// End NPC: 1009943

using namespace Sapphire;

class ClsRog011 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestUI8AH

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1009944;
//    static constexpr auto Actor1 = 1009943;
//    static constexpr auto Classjob = 29;
//    static constexpr auto GearsetUnlock = 1905;
//    static constexpr auto LcutBgm0 = 97;
//    static constexpr auto LcutBgm1 = 87;
//    static constexpr auto LcutPos0 = 5120981;
//    static constexpr auto LcutPos1 = 5120983;
//    static constexpr auto LcutPos2 = 5121028;
//    static constexpr auto LcutPos3 = 5404447;
//    static constexpr auto LogmessageMonsterNotePageUnlock = 1020;
//    static constexpr auto Poprange0 = 5341051;
//    static constexpr auto Territorytype0 = 129;
//    static constexpr auto UnlockImageClassRog = 258;

  public:
    ClsRog011() : Sapphire::ScriptAPI::EventScript( 65638 ){}; 
    ~ClsRog011() = default; 

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
      case 1:
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

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 3, NONE, callback );
  }

};

EXPOSE_SCRIPT( ClsRog011 );
