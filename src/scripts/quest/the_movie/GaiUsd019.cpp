// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsd019_01530
// Quest Name: Judgment Bolts and Lightning
// Quest ID: 67066
// Start NPC: 1009294
// End NPC: 1007478

using namespace Sapphire;

class GaiUsd019 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1009294;
//    static constexpr auto Actor1 = 1000587;
//    static constexpr auto Actor2 = 5010000;
//    static constexpr auto Actor3 = 1007478;
//    static constexpr auto Eobject0 = 2004430;
//    static constexpr auto EventActionSympathy = 19;
//    static constexpr auto Instancedungeon0 = 20023;
//    static constexpr auto LocAction0 = 945;
//    static constexpr auto LocAction1 = 954;
//    static constexpr auto LocAction2 = 605;
//    static constexpr auto LocAction3 = 953;
//    static constexpr auto LocAction4 = 962;
//    static constexpr auto LocAction5 = 950;
//    static constexpr auto LocActor0 = 1005163;
//    static constexpr auto LocActorPos0 = 4891556;
//    static constexpr auto LocQuestUriCheck01 = 66548;
//    static constexpr auto LocQuestUriCheck02 = 66734;
//    static constexpr auto LocQuestUriCheck03 = 66948;
//    static constexpr auto LocQuestUriCheck04 = 66949;
//    static constexpr auto LocQuestUriCheck05 = 65579;
//    static constexpr auto LocQuestUriCheck06 = 65626;
//    static constexpr auto LocQuestUriCheck07 = 68684;
//    static constexpr auto Screenimage0 = 223;
//    static constexpr auto UnlockAddNewContentToCf = 3702;

  public:
    GaiUsd019() : Sapphire::ScriptAPI::EventScript( 67066 ){}; 
    ~GaiUsd019() = default; 

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

    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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

    player.playScene( getId(), 7, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsd019 );
