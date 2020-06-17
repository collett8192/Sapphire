// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: FesSum204_02139
// Quest Name: Who Let the Bombs Out
// Quest ID: 67675
// Start NPC: 1017211
// End NPC: 1017201

using namespace Sapphire;

class FesSum204 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetFestivalQuestWorkFlag
    // GetQuestBitFlag8
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL
    // SaveFestivalQuestWorkFlag

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
//    static constexpr auto ActionTimelineBattleWeaponGuard = 78;
//    static constexpr auto ActionTimelineEmoteAmazed = 689;
//    static constexpr auto ActionTimelineEmoteAngry = 690;
//    static constexpr auto ActionTimelineEmoteCheer = 695;
//    static constexpr auto ActionTimelineEmoteClap = 696;
//    static constexpr auto ActionTimelineEmoteClap = 696;
//    static constexpr auto ActionTimelineEmoteFume = 704;
//    static constexpr auto ActionTimelineEmoteGoodbye = 705;
//    static constexpr auto ActionTimelineEmoteHuh = 707;
//    static constexpr auto ActionTimelineEmoteJoy = 708;
//    static constexpr auto ActionTimelineEmoteJoyStrong = 709;
//    static constexpr auto ActionTimelineEmoteKneel = 710;
//    static constexpr auto ActionTimelineEmoteMakeAct = 714;
//    static constexpr auto ActionTimelineEmoteMe = 715;
//    static constexpr auto ActionTimelineEmoteNoStrong = 717;
//    static constexpr auto ActionTimelineEmotePsych = 724;
//    static constexpr auto ActionTimelineEmoteShocked = 729;
//    static constexpr auto ActionTimelineEmoteStagger = 733;
//    static constexpr auto ActionTimelineEmoteStop = 4255;
//    static constexpr auto ActionTimelineEmoteUpset = 737;
//    static constexpr auto ActionTimelineEmoteYesStrong = 740;
//    static constexpr auto ActionTimelineEventBattleCorpse = 73;
//    static constexpr auto ActionTimelineEventFlyoff = 4285;
//    static constexpr auto ActionTimelineEventGirdUp = 1022;
//    static constexpr auto ActionTimelineEventKnee = 934;
//    static constexpr auto ActionTimelineEventSurprised = 1005;
//    static constexpr auto ActionTimelineFacialWorry = 620;
//    static constexpr auto Actor0 = 1017211;
//    static constexpr auto Actor1 = 1017229;
//    static constexpr auto Actor2 = 1017201;
//    static constexpr auto BindActor1 = 6262731;
//    static constexpr auto Enemy0 = 5765;
//    static constexpr auto Eobject0 = 2007143;
//    static constexpr auto Eobject1 = 2007144;
//    static constexpr auto Eobject2 = 2007396;
//    static constexpr auto Eobject3 = 2007166;
//    static constexpr auto EventActionExplosion = 1033;
//    static constexpr auto Item0 = 2001973;
//    static constexpr auto Item1 = 2001974;
//    static constexpr auto LcutSe0 = 59;
//    static constexpr auto LocActor0 = 1017250;
//    static constexpr auto LocActor2 = 1017671;
//    static constexpr auto LocActor3 = 1017672;
//    static constexpr auto LocMusic0 = 93;
//    static constexpr auto LocMusic1 = 87;
//    static constexpr auto LocMusic2 = 83;
//    static constexpr auto LocMusic3 = 380;
//    static constexpr auto Quest0 = 67675;

  public:
    FesSum204() : Sapphire::ScriptAPI::EventScript( 67675 ){}; 
    ~FesSum204() = default; 

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
        Scene00014( player );
        break;
      }
    }
  }

//  void onBNpcKill( uint32_t npcId, Entity::Player& player ) override
//  {
//    switch( npcId )
//    {
//      case Enemy0: { break; }
//    }
//  }

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
      Scene00008( player );
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

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
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

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 17, NONE, callback );
  }

};

EXPOSE_SCRIPT( FesSum204 );
