// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: FesAnv502_03661
// Quest Name: Messages from Distant Shores
// Quest ID: 69197
// Start NPC: 1031192
// End NPC: 1031192

using namespace Sapphire;

class FesAnv502 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL
    // GetQuestUI8CH
    // GetQuestUI8CL
    // GetQuestUI8DH

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1031192;
//    static constexpr auto Eobject0 = 2010617;
//    static constexpr auto Eobject1 = 2010761;
//    static constexpr auto Eobject2 = 2010762;
//    static constexpr auto Eventaction0 = 1;
//    static constexpr auto Item0 = 2002845;
//    static constexpr auto Item1 = 2002902;
//    static constexpr auto Item2 = 2002903;
//    static constexpr auto LocActSit01 = 1065;
//    static constexpr auto LocActSit02 = 804;
//    static constexpr auto LocEnpcCamman01 = 1010402;
//    static constexpr auto LocEnpcEp0101 = 1031569;
//    static constexpr auto LocEnpcEp0201 = 1031575;
//    static constexpr auto LocEnpcEp0301 = 1031568;
//    static constexpr auto LocEnpcEp0401 = 1031572;
//    static constexpr auto LocEnpcEp0501 = 1031574;
//    static constexpr auto LocEnpcEp0601 = 1017666;
//    static constexpr auto LocEnpcEp0701 = 1031656;
//    static constexpr auto LocEnpcEp0801 = 1031571;
//    static constexpr auto LocEnpcEp0901 = 1031570;
//    static constexpr auto LocEnpcEp1001 = 1031657;
//    static constexpr auto LocEnpcEp1101 = 1031658;
//    static constexpr auto LocEnpcEp1301 = 1031573;
//    static constexpr auto LocEnpcEp1401 = 1017632;
//    static constexpr auto LocEnpcEp140201 = 1031645;
//    static constexpr auto LocEnpcEp140202 = 1031646;
//    static constexpr auto LocEnpcEp140203 = 1031647;
//    static constexpr auto LocEnpcEp140301 = 1031648;
//    static constexpr auto LocEnpcEp140401 = 1031649;
//    static constexpr auto LocEnpcEp140402 = 1031652;
//    static constexpr auto LocEnpcEp140501 = 1031650;
//    static constexpr auto LocEnpcEpmin01 = 1007968;
//    static constexpr auto LocEnpcEpmin02 = 1031567;
//    static constexpr auto LocEnpcEpmin03 = 1017664;
//    static constexpr auto LocLevelPosGuest01 = 8017323;
//    static constexpr auto LocLevelPosSkp01 = 8017123;
//    static constexpr auto LocMainQuest01 = 66060;
//    static constexpr auto LocMainQuest02 = 67205;
//    static constexpr auto LocMainQuest03 = 68089;
//    static constexpr auto LocMainQuest04 = 69190;
//    static constexpr auto LocWeather01 = 1;

  public:
    FesAnv502() : Sapphire::ScriptAPI::EventScript( 69197 ){}; 
    ~FesAnv502() = default; 

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
        Scene00003( player );
        break;
      }
      case 255:
      {
        Scene00009( player );
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
    };

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
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

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( FesAnv502 );
