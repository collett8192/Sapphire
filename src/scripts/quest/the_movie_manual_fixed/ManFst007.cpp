// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ManFst007_00447
// Quest Name: To Guard a Guardian
// Quest ID: 65983
// Start NPC: 1000100
// End NPC: 1003061

using namespace Sapphire;

class ManFst007 : public Sapphire::ScriptAPI::EventScript
{
private:
  // Basic quest information 
  // Quest vars / flags used
  // GetQuestBitFlag16
  // GetQuestBitFlag8
  // GetQuestUI8AH
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
    //      SeqFinish = 255,
  };

  // Entities found in the script data of the quest
  //    static constexpr auto Actor0 = 1000100;
  //    static constexpr auto Actor1 = 1003061;
  //    static constexpr auto Actor10 = 1000721;
  //    static constexpr auto Actor11 = 1000722;
  //    static constexpr auto Actor12 = 1000723;
  //    static constexpr auto Actor13 = 1000724;
  //    static constexpr auto Actor2 = 1000423;
  //    static constexpr auto Actor3 = 1000456;
  //    static constexpr auto Actor4 = 1000457;
  //    static constexpr auto Actor5 = 1000458;
  //    static constexpr auto Actor6 = 1000463;
  //    static constexpr auto Actor7 = 1000464;
  //    static constexpr auto Actor8 = 1000719;
  //    static constexpr auto Actor9 = 1000720;
  //    static constexpr auto CutScene03 = 60;
  //    static constexpr auto Eobject0 = 2001836;
  //    static constexpr auto Eventrange0 = 3854369;
  //    static constexpr auto EventActionSearch = 1;
  //    static constexpr auto Item0 = 2000249;
  //    static constexpr auto LocAction1 = 961;
  //    static constexpr auto LocActor0 = 1003071;
  //    static constexpr auto LocFace1 = 617;
  //    static constexpr auto LocFace2 = 604;
  //    static constexpr auto LocLip1 = 632;
  //    static constexpr auto Ncut01 = 30;
  //    static constexpr auto Ncut02 = 61;
  //    static constexpr auto Poprange0 = 3884000;
  //    static constexpr auto Questbattle0 = 12;
  //    static constexpr auto Seq0Actor0Lq = 90;
  //    static constexpr auto Territorytype0 = 204;
  //    static constexpr auto Territorytype1 = 226;
  //    static constexpr auto Territorytype2 = 148;

public:
  ManFst007() : Sapphire::ScriptAPI::EventScript( 65983 ){}; 
  ~ManFst007() = default; 

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
        Scene00002( player );
        break;
      }
      case 2:
      {
        Scene00003( player );
        break;
      }
      case 3:
      {
        Scene00006( player );
        break;
      }
      case 4:
      {
        Scene00007( player );
        break;
      }
      case 6:
      {
        Scene00020( player );
        break;
      }
      case 255:
      {
        Scene00021( player );
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

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 2 );
    };

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 4 );
    };

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 6 );
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
    };

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( Entity::Player& player )
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

    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 22, NONE, callback );
  }

};

EXPOSE_SCRIPT( ManFst007 );
