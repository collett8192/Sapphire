// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: FesSum205_02140
// Quest Name: A Battle Royal
// Quest ID: 67676
// Start NPC: 1017201
// End NPC: 1017304

using namespace Sapphire;

class FesSum205 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto ActionTimelineEmoteAngry = 690;
//    static constexpr auto ActionTimelineEmoteBlowkiss = 692;
//    static constexpr auto ActionTimelineEmoteBow = 694;
//    static constexpr auto ActionTimelineEmoteCheer = 695;
//    static constexpr auto ActionTimelineEmoteCryUpper = 678;
//    static constexpr auto ActionTimelineEmoteFume = 704;
//    static constexpr auto ActionTimelineEmoteHuh = 707;
//    static constexpr auto ActionTimelineEmoteJoy = 708;
//    static constexpr auto ActionTimelineEmoteJoyStrong = 709;
//    static constexpr auto ActionTimelineEmoteMakeAct = 714;
//    static constexpr auto ActionTimelineEmoteMe = 715;
//    static constexpr auto ActionTimelineEmoteNo = 716;
//    static constexpr auto ActionTimelineEmotePoke = 721;
//    static constexpr auto ActionTimelineEmotePsych = 724;
//    static constexpr auto ActionTimelineEmoteYes = 739;
//    static constexpr auto ActionTimelineEmoteYesStrong = 740;
//    static constexpr auto ActionTimelineEventPose1 = 4281;
//    static constexpr auto ActionTimelineEventSpirit = 1071;
//    static constexpr auto ActionTimelineEventTalkAngry = 768;
//    static constexpr auto ActionTimelineFacialSmile = 605;
//    static constexpr auto Actor0 = 1017201;
//    static constexpr auto Actor1 = 5010000;
//    static constexpr auto Actor2 = 1017304;
//    static constexpr auto Actor3 = 1017305;
//    static constexpr auto BindActor1 = 6277601;
//    static constexpr auto Eobject0 = 2007134;
//    static constexpr auto EventActionWaiting = 10;
//    static constexpr auto Fate0 = 946;
//    static constexpr auto LcutSe0 = 77;
//    static constexpr auto LocActor0 = 1017203;
//    static constexpr auto LocActor1 = 1017206;
//    static constexpr auto LocActor2 = 1017209;
//    static constexpr auto LocActor3 = 1017204;
//    static constexpr auto LocActor4 = 1017207;
//    static constexpr auto LocActor5 = 1017210;
//    static constexpr auto LocMusic0 = 380;
//    static constexpr auto LocMusic1 = 87;
//    static constexpr auto LocMusic2 = 86;
//    static constexpr auto Ncut01 = 1230;
//    static constexpr auto Quest0 = 67675;

  public:
    FesSum205() : Sapphire::ScriptAPI::EventScript( 67676 ){}; 
    ~FesSum205() = default; 

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
        Scene00008( player );
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
      Scene00003( player );
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
      Scene00007( player );
    };

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
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

    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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

EXPOSE_SCRIPT( FesSum205 );
