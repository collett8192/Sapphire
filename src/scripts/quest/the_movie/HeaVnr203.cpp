// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: HeaVnr203_02251
// Quest Name: Toppling the Tyrant
// Quest ID: 67787
// Start NPC: 1014409
// End NPC: 1013714

using namespace Sapphire;

class HeaVnr203 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto ActiontimelineFacialBow = 611;
//    static constexpr auto ActiontimelineFacialDefault = 604;
//    static constexpr auto ActiontimelineFacialSmile = 605;
//    static constexpr auto ActiontimelineFacialSpewing = 617;
//    static constexpr auto ActiontimelineFacialWhat = 619;
//    static constexpr auto Actor0 = 1014409;
//    static constexpr auto Actor1 = 1016637;
//    static constexpr auto Actor2 = 1016997;
//    static constexpr auto Actor3 = 5010000;
//    static constexpr auto Actor4 = 1013714;
//    static constexpr auto Actor5 = 1014407;
//    static constexpr auto Actor6 = 1014408;
//    static constexpr auto BindActor0 = 6199981;
//    static constexpr auto BindActor1 = 5909569;
//    static constexpr auto BindActor2 = 5909571;
//    static constexpr auto BindActor3 = 6199980;
//    static constexpr auto BindActor4 = 6217263;
//    static constexpr auto EventArms = 1041;
//    static constexpr auto EventBow = 957;
//    static constexpr auto EventScar = 4224;
//    static constexpr auto Instancedungeon0 = 30032;
//    static constexpr auto LocActor0 = 1014394;
//    static constexpr auto LocEobject0 = 2006353;
//    static constexpr auto LocEobject0Pos = 5909565;
//    static constexpr auto LocPosCam1 = 6234645;
//    static constexpr auto LocPosCam2 = 5926961;
//    static constexpr auto Poprange0 = 6215521;
//    static constexpr auto UnlockAddNewContentToCf = 3702;
//    static constexpr auto UnlockImageDungeon = 374;

  public:
    HeaVnr203() : Sapphire::ScriptAPI::EventScript( 67787 ){}; 
    ~HeaVnr203() = default; 

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

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
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

};

EXPOSE_SCRIPT( HeaVnr203 );
