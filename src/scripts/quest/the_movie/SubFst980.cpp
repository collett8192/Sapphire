// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubFst980_01670
// Quest Name: Kettle to the Mettle
// Quest ID: 67206
// Start NPC: 1008948
// End NPC: 1003075

using namespace Sapphire;

class SubFst980 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
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
//      Seq2 = 2,
//      Seq3 = 3,
//      Seq4 = 4,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1008948;
//    static constexpr auto Actor1 = 1003075;
//    static constexpr auto Actor2 = 5010000;
//    static constexpr auto EventActionSigh = 4229;
//    static constexpr auto Instancedungeon0 = 20008;
//    static constexpr auto Instancedungeon1 = 20010;
//    static constexpr auto Instancedungeon2 = 20009;
//    static constexpr auto Item0 = 2001942;
//    static constexpr auto Item1 = 2001943;
//    static constexpr auto Item2 = 2001944;
//    static constexpr auto LocAction0 = 241;
//    static constexpr auto LocAction1 = 250;
//    static constexpr auto LocAction2 = 4261;
//    static constexpr auto LocAction3 = 827;
//    static constexpr auto LocAction5 = 1091;
//    static constexpr auto LocAction6 = 936;
//    static constexpr auto LocActor0 = 4311940;
//    static constexpr auto LocActor1 = 4697909;
//    static constexpr auto LocActor2 = 4678141;
//    static constexpr auto LocActor3 = 4328412;
//    static constexpr auto LocBgm0 = 100;
//    static constexpr auto LocBgm1 = 101;
//    static constexpr auto LocBgm2 = 86;
//    static constexpr auto LocBgm3 = 89;
//    static constexpr auto LocFace0 = 606;
//    static constexpr auto LocFace1 = 612;
//    static constexpr auto LocItem0 = 14884;
//    static constexpr auto LocItem1 = 14885;
//    static constexpr auto LocItem2 = 14886;
//    static constexpr auto LocItem3 = 13775;
//    static constexpr auto LocObject0 = 2006975;
//    static constexpr auto LocSe0 = 72;
//    static constexpr auto LocSe1 = 80;
//    static constexpr auto LocVfx0 = 241;
//    static constexpr auto Quest0 = 67747;
//    static constexpr auto Ritem0 = 7883;
//    static constexpr auto Ritem1 = 6268;

  public:
    SubFst980() : Sapphire::ScriptAPI::EventScript( 67206 ){}; 
    ~SubFst980() = default; 

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
      player.updateQuest( getId(), 1 );
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
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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

};

EXPOSE_SCRIPT( SubFst980 );
