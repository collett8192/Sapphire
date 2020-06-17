// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: StmBdz504_02755
// Quest Name: Merchant for a Day
// Quest ID: 68291
// Start NPC: 1019349
// End NPC: 1019349

using namespace Sapphire;

class StmBdz504 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestUI8AL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1019349;
//    static constexpr auto LocActor0 = 1022487;
//    static constexpr auto LocActor1 = 1022488;
//    static constexpr auto LocActor10 = 1019569;
//    static constexpr auto LocActor11 = 1023823;
//    static constexpr auto LocActor12 = 1023824;
//    static constexpr auto LocActor2 = 1022489;
//    static constexpr auto LocActor3 = 1022490;
//    static constexpr auto LocIdle0 = 808;
//    static constexpr auto LocIdle1 = 4193;
//    static constexpr auto LocPosActor0 = 7013007;
//    static constexpr auto LocPosActor1 = 7013008;
//    static constexpr auto LocPosActor10 = 7015637;
//    static constexpr auto LocPosActor100 = 7021737;
//    static constexpr auto LocPosActor101 = 7021738;
//    static constexpr auto LocPosActor2 = 7013010;
//    static constexpr auto LocPosActor200 = 7021739;
//    static constexpr auto LocPosActor201 = 7021740;
//    static constexpr auto LocPosCam0 = 7013006;

  public:
    StmBdz504() : Sapphire::ScriptAPI::EventScript( 68291 ){}; 
    ~StmBdz504() = default; 

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
        Scene00003( player );
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
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
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

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( StmBdz504 );
