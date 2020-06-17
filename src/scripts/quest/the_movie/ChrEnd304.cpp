// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ChrEnd304_02364
// Quest Name: The Life and Lies of Father Saturnois
// Quest ID: 67900
// Start NPC: 1017926
// End NPC: 1017929

using namespace Sapphire;

class ChrEnd304 : public Sapphire::ScriptAPI::EventScript
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
//      Seq2 = 2,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineEventBaseWaiter = 1072;
//    static constexpr auto ActionTimelineEventBow = 957;
//    static constexpr auto ActionTimelineEventGlassSet = 1038;
//    static constexpr auto ActionTimelineEventGlassSetUp = 1044;
//    static constexpr auto ActionTimelineEventMenace = 946;
//    static constexpr auto ActionTimelineEventMenace = 946;
//    static constexpr auto ActionTimelineEventSigh = 4229;
//    static constexpr auto ActionTimelineEventTalkFinger = 4194;
//    static constexpr auto ActionTimelineEventTalkJoke = 4220;
//    static constexpr auto ActionTimelineFacialBad = 622;
//    static constexpr auto ActionTimelineFacialCry = 612;
//    static constexpr auto Actor0 = 1017926;
//    static constexpr auto Actor1 = 1015966;
//    static constexpr auto Actor10 = 1017929;
//    static constexpr auto Actor11 = 1018287;
//    static constexpr auto Actor2 = 1015967;
//    static constexpr auto Actor3 = 1018300;
//    static constexpr auto Actor4 = 1017927;
//    static constexpr auto Actor5 = 1017928;
//    static constexpr auto Actor6 = 1017890;
//    static constexpr auto Actor7 = 1017895;
//    static constexpr auto Actor8 = 1017896;
//    static constexpr auto Actor9 = 1015977;
//    static constexpr auto CutSceneN01 = 1349;
//    static constexpr auto LocActor0 = 1015863;
//    static constexpr auto LocActor1 = 1015864;
//    static constexpr auto LocActor2 = 1015865;
//    static constexpr auto LocActor3 = 1015867;
//    static constexpr auto LocActor4 = 1015869;
//    static constexpr auto LocActor5 = 1015884;
//    static constexpr auto LocActor6 = 1015870;
//    static constexpr auto LocActor7 = 1018385;
//    static constexpr auto LocPosActor0 = 6572935;
//    static constexpr auto LocPosActor1 = 6573661;
//    static constexpr auto LocPosActor101 = 6628926;
//    static constexpr auto LocPosActor102 = 6628928;
//    static constexpr auto LocPosActor2 = 6573662;
//    static constexpr auto Poprange0 = 6522975;
//    static constexpr auto Poprange1 = 6522997;
//    static constexpr auto QstActor0 = 6078127;
//    static constexpr auto QstActor1 = 6078128;
//    static constexpr auto QstActor2 = 6522962;

  public:
    ChrEnd304() : Sapphire::ScriptAPI::EventScript( 67900 ){}; 
    ~ChrEnd304() = default; 

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
        Scene00011( player );
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

    player.playScene( getId(), 2, NONE, callback );
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

    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
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
      Scene00009( player );
    };

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
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

  void Scene00011( Entity::Player& player )
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

    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 12, NONE, callback );
  }

};

EXPOSE_SCRIPT( ChrEnd304 );
