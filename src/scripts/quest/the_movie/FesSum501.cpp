// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: FesSum501_03663
// Quest Name: Feels Like Moonfire
// Quest ID: 69199
// Start NPC: 1031437
// End NPC: 1031438

using namespace Sapphire;

class FesSum501 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1031437;
//    static constexpr auto Actor1 = 1031438;
//    static constexpr auto LocAction01 = 1002;
//    static constexpr auto LocAction02 = 4301;
//    static constexpr auto LocAction03 = 4302;
//    static constexpr auto LocAction04 = 5665;
//    static constexpr auto LocActor01 = 1031449;
//    static constexpr auto LocActor02 = 1031450;
//    static constexpr auto LocActor03 = 1031451;
//    static constexpr auto LocActor04 = 1031452;
//    static constexpr auto LocActor05 = 1031453;
//    static constexpr auto LocActor06 = 1031455;
//    static constexpr auto LocActor07 = 1031456;
//    static constexpr auto LocActor08 = 1031457;
//    static constexpr auto LocActor09 = 1031458;
//    static constexpr auto LocIdle01 = 5523;
//    static constexpr auto LocSe01 = 42;
//    static constexpr auto QstFessum005 = 67074;
//    static constexpr auto QstFessum010 = 67079;
//    static constexpr auto QstFessum104 = 67663;
//    static constexpr auto QstFessum201 = 67672;
//    static constexpr auto QstFessum205 = 67676;
//    static constexpr auto QstFessum301 = 68492;
//    static constexpr auto QstFessum305 = 68496;
//    static constexpr auto QstFessum401 = 68671;
//    static constexpr auto QstFessum403 = 68673;

  public:
    FesSum501() : Sapphire::ScriptAPI::EventScript( 69199 ){}; 
    ~FesSum501() = default; 

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
        Scene00004( player );
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

    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
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

    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( FesSum501 );
