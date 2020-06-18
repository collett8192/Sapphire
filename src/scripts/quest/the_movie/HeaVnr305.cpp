// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: HeaVnr305_02339
// Quest Name: Of Endings and Beginnings
// Quest ID: 67875
// Start NPC: 1017944
// End NPC: 1013714

using namespace Sapphire;

class HeaVnr305 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActiontimelineEventBaseStandRead = 937;
//    static constexpr auto ActiontimelineEventFacialDefault = 604;
//    static constexpr auto ActiontimelineEventFacialSmile = 605;
//    static constexpr auto Actor0 = 1017944;
//    static constexpr auto Actor1 = 1017945;
//    static constexpr auto Actor2 = 1018346;
//    static constexpr auto Actor3 = 1013714;
//    static constexpr auto Actor4 = 1016637;
//    static constexpr auto Actor5 = 1016997;
//    static constexpr auto Actor6 = 1014402;
//    static constexpr auto BindActor1 = 6446099;
//    static constexpr auto BindActor2 = 5901183;
//    static constexpr auto EventArms = 1041;
//    static constexpr auto EventBaseLink = 1009;
//    static constexpr auto EventBow = 957;
//    static constexpr auto EventLink = 1002;
//    static constexpr auto Item0 = 2002027;
//    static constexpr auto LocActor0 = 1011889;
//    static constexpr auto LocActor1 = 1011900;
//    static constexpr auto LocActor2 = 1014399;
//    static constexpr auto LocActor3 = 1003836;
//    static constexpr auto LocActor4 = 1003837;
//    static constexpr auto LocActor5 = 1014395;
//    static constexpr auto LocActor6 = 1014401;
//    static constexpr auto LocArmor01 = 26;
//    static constexpr auto LocEobject0 = 2006353;
//    static constexpr auto LocEobject0Pos = 5909565;
//    static constexpr auto LocEobject1 = 2007429;
//    static constexpr auto LocEobject1Pos = 6542526;
//    static constexpr auto LocHideActor1 = 1016637;
//    static constexpr auto LocHideActor2 = 1016997;
//    static constexpr auto LocHideActor3 = 1014402;
//    static constexpr auto LocPosActor0 = 6544622;
//    static constexpr auto LocPosActor1 = 6546245;
//    static constexpr auto SeIdEventLinkshellGc = 42;

  public:
    HeaVnr305() : Sapphire::ScriptAPI::EventScript( 67875 ){}; 
    ~HeaVnr305() = default; 

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
      player.updateQuest( getId(), 255 );
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

};

EXPOSE_SCRIPT( HeaVnr305 );
