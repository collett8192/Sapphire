// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: FesPdy306_02408
// Quest Name: Idols Give Back
// Quest ID: 67944
// Start NPC: 1018621
// End NPC: 1018402

using namespace Sapphire;

class FesPdy306 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1018621;
//    static constexpr auto Actor1 = 1018641;
//    static constexpr auto Actor2 = 1018642;
//    static constexpr auto Actor3 = 1018643;
//    static constexpr auto Actor4 = 1018644;
//    static constexpr auto Actor5 = 1018402;
//    static constexpr auto Actor6 = 1018741;
//    static constexpr auto Actor7 = 1018742;
//    static constexpr auto Actor8 = 1018743;
//    static constexpr auto LocActor01 = 1019533;
//    static constexpr auto LocActor02 = 1019534;
//    static constexpr auto LocActor03 = 1019535;
//    static constexpr auto LocAct01 = 4818;
//    static constexpr auto LocAct01Start = 4817;
//    static constexpr auto LocBgmOdayaka01 = 400;
//    static constexpr auto LocBindEnpc01 = 6563460;
//    static constexpr auto LocBindEnpc02 = 6563461;
//    static constexpr auto LocBindEnpc03 = 6563462;
//    static constexpr auto LocBindEnpc04 = 6563463;
//    static constexpr auto LocBindEnpc05 = 6563464;
//    static constexpr auto LocBindEnpc06 = 6563465;
//    static constexpr auto LocBindEnpcShop = 6610245;
//    static constexpr auto LocBindPri01 = 6610242;
//    static constexpr auto LocBindPri02 = 6610243;
//    static constexpr auto LocBindPri03 = 6610244;
//    static constexpr auto LocEnpcAudie01 = 1019625;
//    static constexpr auto LocEnpcAudie02 = 1019626;
//    static constexpr auto LocEnpcAudie03 = 1019627;
//    static constexpr auto LocEnpcAudie04 = 1019628;
//    static constexpr auto LocEnpcAudie05 = 1019629;
//    static constexpr auto LocEnpcAudie06 = 1019630;
//    static constexpr auto LocEnpcAudie07 = 1019631;
//    static constexpr auto LocEnpcAudie08 = 1019632;
//    static constexpr auto LocEnpcAudie09 = 1019633;
//    static constexpr auto LocEnpcAudie10 = 1019634;
//    static constexpr auto LocEnpcAudie11 = 1019635;
//    static constexpr auto LocEnpcAudie12 = 1019636;
//    static constexpr auto LocEnpcAudie13 = 1019637;
//    static constexpr auto LocEnpcAudie14 = 1019656;
//    static constexpr auto LocEnpcRedlent01 = 1008172;
//    static constexpr auto LocEobjVfx01 = 2007732;
//    static constexpr auto LocEobjVfx02 = 2007733;
//    static constexpr auto LocEobjVfx03 = 2007734;
//    static constexpr auto LocQuestAura = 67943;
//    static constexpr auto LocQuestLala = 67937;
//    static constexpr auto LocQuestMiq = 67942;
//    static constexpr auto LocSeKansei01 = 142;
//    static constexpr auto LocSeZawa01 = 124;
//    static constexpr auto Poprange0 = 6645901;

  public:
    FesPdy306() : Sapphire::ScriptAPI::EventScript( 67944 ){}; 
    ~FesPdy306() = default; 

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

    player.playScene( getId(), 1, NONE, callback );
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

EXPOSE_SCRIPT( FesPdy306 );
