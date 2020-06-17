// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubCts824_01550
// Quest Name: Fiery Wings, Fiery Hearts
// Quest ID: 67086
// Start NPC: 1017656
// End NPC: 2007704

using namespace Sapphire;

class SubCts824 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActiontimelineEventArms = 1041;
//    static constexpr auto ActiontimelineEventChocoboWhistleNoSe = 1069;
//    static constexpr auto ActiontimelineEventJump = 966;
//    static constexpr auto ActiontimelineEventLcutHide = 1078;
//    static constexpr auto ActiontimelineEventShow2 = 4305;
//    static constexpr auto Actor0 = 1017656;
//    static constexpr auto Actor1 = 1018765;
//    static constexpr auto Eobject0 = 2007704;
//    static constexpr auto Item0 = 2002052;
//    static constexpr auto LcutActor0 = 1018766;
//    static constexpr auto LcutActor1 = 1018767;
//    static constexpr auto LcutActor2 = 1018768;
//    static constexpr auto LcutActor3 = 1018769;
//    static constexpr auto LcutActor4 = 1018770;
//    static constexpr auto LcutActor5 = 1018971;
//    static constexpr auto LcutActor6 = 1018972;
//    static constexpr auto LcutActor7 = 1018973;
//    static constexpr auto LcutActor8 = 1018974;
//    static constexpr auto MountKirin = 47;
//    static constexpr auto SeEventHorn = 86;
//    static constexpr auto SeEventHouoh = 143;

  public:
    SubCts824() : Sapphire::ScriptAPI::EventScript( 67086 ){}; 
    ~SubCts824() = default; 

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
        Scene00005( player );
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
      Scene00002( player );
    };

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };

    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
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

    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( SubCts824 );
