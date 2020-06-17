// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: LucKma304_03294
// Quest Name: A Desert Crossing
// Quest ID: 68830
// Start NPC: 1028977
// End NPC: 1028980

using namespace Sapphire;

class LucKma304 : public Sapphire::ScriptAPI::EventScript
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
//      Seq5 = 5,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1028977;
//    static constexpr auto Actor1 = 1028976;
//    static constexpr auto Actor2 = 1030871;
//    static constexpr auto Actor3 = 1030606;
//    static constexpr auto Actor4 = 1028978;
//    static constexpr auto Actor5 = 1028980;
//    static constexpr auto Enemy0 = 7926404;
//    static constexpr auto Enemy1 = 7926411;
//    static constexpr auto Enemy2 = 8005227;
//    static constexpr auto Eobject0 = 2009847;
//    static constexpr auto Eobject1 = 2009848;
//    static constexpr auto Eventaction0 = 50;
//    static constexpr auto Eventaction1 = 1;
//    static constexpr auto Eventrange0 = 7925885;
//    static constexpr auto LocAction0 = 805;
//    static constexpr auto LocAction1 = 824;
//    static constexpr auto LocAction2 = 803;
//    static constexpr auto LocAction3 = 812;
//    static constexpr auto LocAction4 = 4201;
//    static constexpr auto LocAction5 = 804;
//    static constexpr auto LocActor0 = 1029465;
//    static constexpr auto LocActor1 = 1029338;
//    static constexpr auto LocActor10 = 1029460;
//    static constexpr auto LocActor11 = 1029461;
//    static constexpr auto LocActor12 = 1029462;
//    static constexpr auto LocActor13 = 1029463;
//    static constexpr auto LocActor14 = 1029464;
//    static constexpr auto LocActor15 = 1029339;
//    static constexpr auto LocActor2 = 1029452;
//    static constexpr auto LocActor3 = 1029453;
//    static constexpr auto LocActor4 = 1029454;
//    static constexpr auto LocActor5 = 1029455;
//    static constexpr auto LocActor6 = 1029456;
//    static constexpr auto LocActor7 = 1029457;
//    static constexpr auto LocActor8 = 1029458;
//    static constexpr auto LocActor9 = 1029459;
//    static constexpr auto LocPos0 = 7981560;
//    static constexpr auto LocPos1 = 8051784;
//    static constexpr auto LocPos10 = 8051786;
//    static constexpr auto LocPos11 = 8051787;
//    static constexpr auto LocPos12 = 8051839;
//    static constexpr auto LocPos2 = 8051777;
//    static constexpr auto LocPos3 = 8051774;
//    static constexpr auto LocPos4 = 8051775;
//    static constexpr auto LocPos5 = 8051778;
//    static constexpr auto LocPos6 = 8051780;
//    static constexpr auto LocPos7 = 8051781;
//    static constexpr auto LocPos8 = 8051783;
//    static constexpr auto LocPos9 = 8051785;
//    static constexpr auto Poprange0 = 7926834;

  public:
    LucKma304() : Sapphire::ScriptAPI::EventScript( 68830 ){}; 
    ~LucKma304() = default; 

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
        Scene00023( player );
        break;
      }
    }
  }

//  void onBNpcKill( uint32_t npcId, Entity::Player& player ) override
//  {
//    switch( npcId )
//    {
//      case Enemy0: { break; }
//      case Enemy1: { break; }
//      case Enemy2: { break; }
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
      Scene00005( player );
    };

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
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
      Scene00013( player );
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
      Scene00015( player );
    };

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00017( player );
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
      Scene00019( player );
    };

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00021( player );
    };

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00022( player );
    };

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
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

    player.playScene( getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( LucKma304 );
