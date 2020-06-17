// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: FesPdy201_02221
// Quest Name: Aligning the Stars
// Quest ID: 67757
// Start NPC: 1016354
// End NPC: 1016356

using namespace Sapphire;

class FesPdy201 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1016354;
//    static constexpr auto Actor1 = 1016356;
//    static constexpr auto LocBgm01 = 196;
//    static constexpr auto LocEnpcPrincess01Lv01 = 1016420;
//    static constexpr auto LocEnpcPrincess01Lv02 = 1016423;
//    static constexpr auto LocEnpcPrincess01Lv03 = 1016426;
//    static constexpr auto LocEnpcPrincess02Lv01 = 1016421;
//    static constexpr auto LocEnpcPrincess02Lv02 = 1016424;
//    static constexpr auto LocEnpcPrincess02Lv03 = 1016427;
//    static constexpr auto LocEnpcPrincess03Lv01 = 1016422;
//    static constexpr auto LocEnpcPrincess03Lv02 = 1016425;
//    static constexpr auto LocEnpcPrincess03Lv03 = 1016428;
//    static constexpr auto LocLevelEnpcQuest01 = 6113859;
//    static constexpr auto LocLevelEnpcShop01 = 6113860;

  public:
    FesPdy201() : Sapphire::ScriptAPI::EventScript( 67757 ){}; 
    ~FesPdy201() = default; 

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

EXPOSE_SCRIPT( FesPdy201 );
