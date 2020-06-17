// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubSea112_00409
// Quest Name: Failure to Lunch
// Quest ID: 65945
// Start NPC: 1002233
// End NPC: 1002233

using namespace Sapphire;

class SubSea112 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL
    // GetQuestUI8CH
    // GetQuestUI8CL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1002233;
//    static constexpr auto Actor1 = 1002453;
//    static constexpr auto Actor2 = 1002455;
//    static constexpr auto Eobject0 = 2000762;
//    static constexpr auto Eobject1 = 2000763;
//    static constexpr auto EventActionGatherShort = 6;
//    static constexpr auto Item0 = 2000218;
//    static constexpr auto Seq0Actor0 = 0;
//    static constexpr auto Seq1Actor1 = 1;
//    static constexpr auto Seq1Actor2 = 2;
//    static constexpr auto Seq1Eobject0 = 3;
//    static constexpr auto Seq1Eobject0Eventactionno = 99;
//    static constexpr auto Seq1Eobject0Eventactionok = 100;
//    static constexpr auto Seq1Eobject1 = 4;
//    static constexpr auto Seq1Eobject1Eventactionno = 97;
//    static constexpr auto Seq1Eobject1Eventactionok = 98;
//    static constexpr auto Seq2Actor0 = 5;
//    static constexpr auto Seq2Actor0Npctradeno = 95;
//    static constexpr auto Seq2Actor0Npctradeok = 96;

  public:
    SubSea112() : Sapphire::ScriptAPI::EventScript( 65945 ){}; 
    ~SubSea112() = default; 

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
        Scene00001( player );
        break;
      }
      case 255:
      {
        Scene00005( player );
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
        player.updateQuest( getId(), 1 );
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
      player.updateQuest( getId(), 255 );
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
    };

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00096( player );
    };

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00095( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 95, NONE, callback );
  }

  void Scene00096( Entity::Player& player )
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

    player.playScene( getId(), 96, NONE, callback );
  }

  void Scene00097( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 97, NONE, callback );
  }

  void Scene00098( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 98, NONE, callback );
  }

  void Scene00099( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 99, NONE, callback );
  }

  void Scene00100( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 100, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubSea112 );
