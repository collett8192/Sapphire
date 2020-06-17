// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: HeaVny221_02288
// Quest Name: The Fate of Stars
// Quest ID: 67824
// Start NPC: 1014565
// End NPC: 1014565

using namespace Sapphire;

class HeaVny221 : public Sapphire::ScriptAPI::EventScript
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
//      Seq3 = 3,
//      Seq4 = 4,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineBaseThink = 4193;
//    static constexpr auto ActionTimelineEmoteBow = 694;
//    static constexpr auto ActionTimelineEmoteGoodbye = 705;
//    static constexpr auto ActionTimelineEmoteGoodbyeSt = 706;
//    static constexpr auto ActionTimelineEmoteHuh = 707;
//    static constexpr auto ActionTimelineEmoteLaugh = 685;
//    static constexpr auto ActionTimelineEmoteMe = 715;
//    static constexpr auto ActionTimelineEmoteShocked = 729;
//    static constexpr auto ActionTimelineEventEat = 963;
//    static constexpr auto ActionTimelineEventPoint = 720;
//    static constexpr auto ActionTimelineEventThink = 669;
//    static constexpr auto Actor0 = 1014565;
//    static constexpr auto Actor1 = 1017115;
//    static constexpr auto Actor2 = 1017167;
//    static constexpr auto ActEventLink = 1002;
//    static constexpr auto BindObj0 = 2007021;
//    static constexpr auto CutSceneN01 = 1214;
//    static constexpr auto Eobject0 = 2005564;
//    static constexpr auto Eobject1 = 2007308;
//    static constexpr auto LcutSe0 = 121;
//    static constexpr auto LcutSe1 = 120;
//    static constexpr auto LcutSe2 = 122;
//    static constexpr auto LocActor0 = 1016760;
//    static constexpr auto LocActor1 = 1011889;
//    static constexpr auto LocActor2 = 1016779;
//    static constexpr auto LocActor3 = 1011863;
//    static constexpr auto LocMusic0 = 85;
//    static constexpr auto LocMusic1 = 83;
//    static constexpr auto LocMusic2 = 97;
//    static constexpr auto Poprange0 = 6244281;
//    static constexpr auto Questbattle0 = 5002;
//    static constexpr auto SeEventLink = 42;
//    static constexpr auto Territorytype0 = 560;
//    static constexpr auto Territorytype1 = 402;

  public:
    HeaVny221() : Sapphire::ScriptAPI::EventScript( 67824 ){}; 
    ~HeaVny221() = default; 

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
        player.sendUrgent( "This quest contains at least one quest battle, " );
        player.sendUrgent( "which has a high change to break the script and get stuck." );
        player.sendUrgent( "Use \"//gm quest sequence <questId> 255\" to skip broken scenes."); 
        player.sendUrgent( "### Hit NO when asked to enter quest battle ###" );
        Scene00000( player );
        break;
      }
      case 1:
      {
        Scene00006( player );
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
      player.updateQuest( getId(), 1 );
    };

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };

    player.playScene( getId(), 6, NONE, callback );
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

    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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

    player.playScene( getId(), 11, NONE, callback );
  }

};

EXPOSE_SCRIPT( HeaVny221 );
