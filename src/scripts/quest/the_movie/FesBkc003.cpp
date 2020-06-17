// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: FesBkc003_03160
// Quest Name: Messenger of the Winds
// Quest ID: 68696
// Start NPC: 1026870
// End NPC: 1026869

using namespace Sapphire;

class FesBkc003 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto ActionTimelineEventLookBackLeft = 4257;
//    static constexpr auto ActionTimelineStopCall = 4255;
//    static constexpr auto Actor0 = 1026870;
//    static constexpr auto Actor1 = 1026867;
//    static constexpr auto Actor2 = 1026868;
//    static constexpr auto Actor3 = 1026869;
//    static constexpr auto Actor4 = 1026872;
//    static constexpr auto BgmDaemons = 608;
//    static constexpr auto BgmHammerhead = 605;
//    static constexpr auto BgmLuna = 609;
//    static constexpr auto BgmRelax = 607;
//    static constexpr auto BgmSafeHeaven = 610;
//    static constexpr auto BgmValseDiFantastica = 606;
//    static constexpr auto BindNocSeq3 = 7725081;
//    static constexpr auto Eobject0 = 2009666;
//    static constexpr auto LocBkcCid = 1003855;
//    static constexpr auto LocBkcMan = 1027163;
//    static constexpr auto LocJakuemi = 6215;
//    static constexpr auto LocKanmu = 6216;
//    static constexpr auto LocKomaru = 625;
//    static constexpr auto LocMeiso = 6227;
//    static constexpr auto LocNigawa = 6229;
//    static constexpr auto NcutFesbkc00310 = 1916;
//    static constexpr auto NcutFesbkc00410 = 1917;
//    static constexpr auto Poprange0 = 7781193;
//    static constexpr auto Poprange1 = 7730931;
//    static constexpr auto Poprange2 = 7730946;
//    static constexpr auto Questbattle0 = 5027;
//    static constexpr auto ScreenimageAccepted = 707;
//    static constexpr auto ScreenimageComplete = 708;
//    static constexpr auto SeDensho = 200;
//    static constexpr auto SeShutter = 201;
//    static constexpr auto Territorytype0 = 834;
//    static constexpr auto Territorytype1 = 833;

  public:
    FesBkc003() : Sapphire::ScriptAPI::EventScript( 68696 ){}; 
    ~FesBkc003() = default; 

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
      case 2:
      {
        Scene00011( player );
        break;
      }
      case 255:
      {
        Scene00012( player );
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

    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
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
      player.updateQuest( getId(), 2 );
    };

    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
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

    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( FesBkc003 );
