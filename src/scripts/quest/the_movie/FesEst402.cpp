// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: FesEst402_03080
// Quest Name: Uneggspected Encounters
// Quest ID: 68616
// Start NPC: 1025251
// End NPC: 1025251

using namespace Sapphire;

class FesEst402 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AL
    // GetQuestUI8BH

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      Seq2 = 2,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActiontimelineEventCome = 4255;
//    static constexpr auto ActiontimelineEventJoyGirl = 4301;
//    static constexpr auto ActiontimelineEventSpecialJoy = 1059;
//    static constexpr auto Actor0 = 1025251;
//    static constexpr auto BgmSeasonEaster = 196;
//    static constexpr auto Eobject0 = 2009427;
//    static constexpr auto Eobject1 = 2009428;
//    static constexpr auto Eobject2 = 2009429;
//    static constexpr auto Eventaction0 = 11;
//    static constexpr auto Eventaction1 = 1;
//    static constexpr auto Item0 = 2002461;
//    static constexpr auto LcutActor0 = 1012445;
//    static constexpr auto LcutActor1 = 1015912;
//    static constexpr auto LcutActor10 = 1009291;
//    static constexpr auto LcutActor11 = 1020958;
//    static constexpr auto LcutActor12 = 1008184;
//    static constexpr auto LcutActor13 = 1016816;
//    static constexpr auto LcutActor2 = 1025192;
//    static constexpr auto LcutActor3 = 1011254;
//    static constexpr auto LcutActor4 = 1007967;
//    static constexpr auto LcutActor5 = 1025193;
//    static constexpr auto LcutActor6 = 1025194;
//    static constexpr auto LcutActor7 = 1021391;
//    static constexpr auto LcutActor8 = 1020922;
//    static constexpr auto LcutActor9 = 1021038;
//    static constexpr auto LcutCam0 = 1003125;
//    static constexpr auto LcutEobj0 = 2009440;
//    static constexpr auto LcutPos0 = 7268992;
//    static constexpr auto QstClsarc006 = 65612;
//    static constexpr auto QstClslnc002 = 65571;
//    static constexpr auto QstClslnc006 = 65975;
//    static constexpr auto QstClslnc997 = 65679;
//    static constexpr auto SeEventOpenPackage = 78;

  public:
    FesEst402() : Sapphire::ScriptAPI::EventScript( 68616 ){}; 
    ~FesEst402() = default; 

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
        Scene00010( player );
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
      Scene00004( player );
    };

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
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

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };

    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 7, NONE, callback );
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
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
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

    player.playScene( getId(), 10, NONE, callback );
  }

};

EXPOSE_SCRIPT( FesEst402 );
