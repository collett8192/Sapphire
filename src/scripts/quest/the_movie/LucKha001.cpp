// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: LucKha001_03672
// Quest Name: Towards the Firmament
// Quest ID: 69208
// Start NPC: 2010850
// End NPC: 1031684

using namespace Sapphire;

class LucKha001 : public Sapphire::ScriptAPI::EventScript
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
//      Seq2 = 2,
//      Seq3 = 3,
//      Seq4 = 4,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1031682;
//    static constexpr auto Actor1 = 1031989;
//    static constexpr auto Actor2 = 1031990;
//    static constexpr auto Actor3 = 1031684;
//    static constexpr auto Actor4 = 1031685;
//    static constexpr auto Eobject0 = 2010850;
//    static constexpr auto Eobject1 = 2010920;
//    static constexpr auto Item0 = 2002954;
//    static constexpr auto LevelEnpcId0 = 8156345;
//    static constexpr auto LevelEnpcId1 = 8144719;
//    static constexpr auto LevelEnpcId2 = 8193357;
//    static constexpr auto LocActor0 = 1007675;
//    static constexpr auto LocActor1 = 1031687;
//    static constexpr auto LocActor10 = 1032014;
//    static constexpr auto LocActor11 = 1032015;
//    static constexpr auto LocActor12 = 1032016;
//    static constexpr auto LocActor2 = 1011895;
//    static constexpr auto LocActor3 = 1017627;
//    static constexpr auto LocActor4 = 1017626;
//    static constexpr auto LocActor5 = 1015884;
//    static constexpr auto LocActor6 = 1011894;
//    static constexpr auto LocActor7 = 1015892;
//    static constexpr auto LocActor8 = 1017682;
//    static constexpr auto LocActor9 = 1031688;
//    static constexpr auto LocEnpcId0 = 1012384;
//    static constexpr auto LocEnpcId1 = 1015991;
//    static constexpr auto LocEnpcId2 = 1015448;
//    static constexpr auto LocEnpcId3 = 1015449;
//    static constexpr auto LocEnpcId4 = 1031681;
//    static constexpr auto LocMotion0 = 1072;
//    static constexpr auto LocMotion1 = 808;
//    static constexpr auto LocMotion2 = 1038;
//    static constexpr auto LocMotion3 = 845;
//    static constexpr auto LocMotion4 = 5703;
//    static constexpr auto LocMotion5 = 5700;
//    static constexpr auto Poprange0 = 8145046;
//    static constexpr auto Quest0 = 68441;
//    static constexpr auto Quest1 = 66038;
//    static constexpr auto Quest2 = 67762;
//    static constexpr auto Territorytype0 = 886;

  public:
    LucKha001() : Sapphire::ScriptAPI::EventScript( 69208 ){}; 
    ~LucKha001() = default; 

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
      case 2:
      {
        Scene00013( player );
        break;
      }
      case 255:
      {
        Scene00014( player );
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
      Scene00009( player );
    };

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
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
      player.updateQuest( getId(), 2 );
    };

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
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

    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
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

EXPOSE_SCRIPT( LucKha001 );
