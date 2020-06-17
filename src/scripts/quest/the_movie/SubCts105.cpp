// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubCts105_01524
// Quest Name: Corpse Groom
// Quest ID: 67060
// Start NPC: 1001894
// End NPC: 1009367

using namespace Sapphire;

class SubCts105 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1001894;
//    static constexpr auto Actor1 = 1009366;
//    static constexpr auto Actor2 = 1001173;
//    static constexpr auto Actor3 = 5010000;
//    static constexpr auto Actor4 = 1009367;
//    static constexpr auto Bindactor0 = 3643138;
//    static constexpr auto Eobject0 = 2004329;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Instancedungeon0 = 24;
//    static constexpr auto LocActor0 = 1004618;
//    static constexpr auto LocActorPos0 = 4890009;
//    static constexpr auto LocActorPos1 = 1009233;
//    static constexpr auto LocBgm1 = 78;
//    static constexpr auto LocFace1 = 611;
//    static constexpr auto LocFace10 = 617;
//    static constexpr auto LocFace2 = 620;
//    static constexpr auto LocFace3 = 612;
//    static constexpr auto LocFace4 = 614;
//    static constexpr auto LocFace5 = 615;
//    static constexpr auto LocFace6 = 619;
//    static constexpr auto LocFace7 = 618;
//    static constexpr auto LocFace8 = 606;
//    static constexpr auto LocPosActor1 = 4891448;
//    static constexpr auto LocPosActor2 = 4891451;
//    static constexpr auto LocPosActor3 = 4891456;
//    static constexpr auto LocPosActor4 = 4891457;
//    static constexpr auto LocPosActor5 = 4893405;
//    static constexpr auto LocPosActor6 = 4893406;
//    static constexpr auto LocPosCam1 = 4893407;
//    static constexpr auto NcutEvent001 = 577;
//    static constexpr auto UnlockAddNewContentToCf = 3702;
//    static constexpr auto UnlockDungeonTamTaraHard = 221;

  public:
    SubCts105() : Sapphire::ScriptAPI::EventScript( 67060 ){}; 
    ~SubCts105() = default; 

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
      Scene00003( player );
    };

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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

};

EXPOSE_SCRIPT( SubCts105 );
