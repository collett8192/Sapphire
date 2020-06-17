// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: FesGsc202_03134
// Quest Name: Love and Kupo Nuts
// Quest ID: 68670
// Start NPC: 1025927
// End NPC: 1025927

using namespace Sapphire;

class FesGsc202 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetFestivalQuestWorkFlag
    // GetQuestBitFlag8
    // GetQuestUI8AL
    // SaveFestivalQuestWorkFlag

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      LocMakerMogSeq2 = MAKER_MOG_SEQ2,
//      LocMakerNigSeq1 = MAKER_NIG_SEQ1,
//      LocMakerPcSeq1 = MAKER_PC_SEQ1,
//      LocMakerSeq255 = MAKER_SEQ255,
//      Seq0 = 0,
//      Seq1 = 1,
//      Seq2 = 2,
//      Seq3 = 3,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1025927;
//    static constexpr auto Actor1 = 1025928;
//    static constexpr auto Actor2 = 1025958;
//    static constexpr auto Actor3 = 1025959;
//    static constexpr auto Actor4 = 1025960;
//    static constexpr auto Actor5 = 1025961;
//    static constexpr auto Actor6 = 1025953;
//    static constexpr auto Actor7 = 1025954;
//    static constexpr auto BindGirlOffer = 7454013;
//    static constexpr auto Eobject0 = 2009557;
//    static constexpr auto Eobject1 = 2009558;
//    static constexpr auto Eobject2 = 2009559;
//    static constexpr auto Eventaction0 = 11;
//    static constexpr auto EventActionKashige = 958;
//    static constexpr auto EventActionManzoku = 1023;
//    static constexpr auto LocAction1 = 965;
//    static constexpr auto LocAction3 = 954;
//    static constexpr auto LocBgm1 = 101;
//    static constexpr auto LocDanceM = 4278;
//    static constexpr auto LocJakuemi = 6215;
//    static constexpr auto LocLeftTrun = 4257;
//    static constexpr auto LocMakerMogSeq2 = 7518333;
//    static constexpr auto LocMakerNigSeq1 = 7518044;
//    static constexpr auto LocMakerPcSeq1 = 7517851;
//    static constexpr auto LocMakerPcSeq2 = 7517850;
//    static constexpr auto LocMakerSeq255 = 7521252;
//    static constexpr auto LocMeiso = 6227;
//    static constexpr auto LocMob001 = 1026084;
//    static constexpr auto LocMogbDel255 = 1025953;
//    static constexpr auto LocMoggDel255 = 1025954;
//    static constexpr auto LocMogBoy = 1025973;
//    static constexpr auto LocMogGirl = 1025972;
//    static constexpr auto LocNigawa = 6229;
//    static constexpr auto LocNigiBoy = 1026073;
//    static constexpr auto LocNigiFmen = 1026072;
//    static constexpr auto LocOjoDele = 1025961;
//    static constexpr auto LocRightTrun = 4256;
//    static constexpr auto LocSeHimei = 116;
//    static constexpr auto LocSong = 4226;
//    static constexpr auto LocThinkUp = 589;
//    static constexpr auto LocToshiDele = 1025960;
//    static constexpr auto LocWink = 621;
//    static constexpr auto LocWis = 1026078;
//    static constexpr auto LocWisDele = 1011142;
//    static constexpr auto Poprange0 = 7536696;
//    static constexpr auto QuestFesgsc202 = 68670;

  public:
    FesGsc202() : Sapphire::ScriptAPI::EventScript( 68670 ){}; 
    ~FesGsc202() = default; 

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
        Scene00015( player );
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
      Scene00005( player );
    };

    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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

    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
      Scene00012( player );
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
      Scene00013( player );
    };

    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
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

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 16, NONE, callback );
  }

};

EXPOSE_SCRIPT( FesGsc202 );
