// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: FesXms204_02378
// Quest Name: A Starlight Story
// Quest ID: 67914
// Start NPC: 1017811
// End NPC: 1017811

using namespace Sapphire;

class FesXms204 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1017811;
//    static constexpr auto Actor1 = 1018227;
//    static constexpr auto Actor2 = 1018290;
//    static constexpr auto Eobject0 = 2007500;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2002016;
//    static constexpr auto LocAct01 = 4811;
//    static constexpr auto LocAct02 = 788;
//    static constexpr auto LocActSleep01 = 986;
//    static constexpr auto LocActSleep02 = 989;
//    static constexpr auto LocBgm01 = 175;
//    static constexpr auto LocBgm02 = 101;
//    static constexpr auto LocBindActor1 = 6502858;
//    static constexpr auto LocBindActor10 = 6483514;
//    static constexpr auto LocBindActor11 = 6515210;
//    static constexpr auto LocBindActor2 = 6502859;
//    static constexpr auto LocBindActor3 = 6502861;
//    static constexpr auto LocBindActor4 = 6502862;
//    static constexpr auto LocBindActor5 = 6483510;
//    static constexpr auto LocBindActor6 = 6483498;
//    static constexpr auto LocBindActor7 = 6483499;
//    static constexpr auto LocBindActor8 = 6483509;
//    static constexpr auto LocBindActor9 = 6483510;
//    static constexpr auto LocEnpcGuestAlph10 = 1017831;
//    static constexpr auto LocEnpcGuestAym12 = 1017833;
//    static constexpr auto LocEnpcGuestGod01 = 1017823;
//    static constexpr auto LocEnpcGuestIda05 = 1017827;
//    static constexpr auto LocEnpcGuestNanamo09 = 1017830;
//    static constexpr auto LocEnpcGuestPaie02 = 1017824;
//    static constexpr auto LocEnpcGuestPapa06 = 1018210;
//    static constexpr auto LocEnpcGuestTata11 = 1017832;
//    static constexpr auto LocEnpcGuestThan03 = 1017825;
//    static constexpr auto LocEnpcGuestThanVer204 = 1017826;
//    static constexpr auto LocEnpcGuestYsht07 = 1017828;
//    static constexpr auto LocEnpcGuestYshtVer208 = 1017829;
//    static constexpr auto LocEobj01 = 2007501;
//    static constexpr auto LocEobj02 = 2007540;
//    static constexpr auto LocQuestAlphCheck01 = 65589;
//    static constexpr auto LocQuestCheckMy = 67914;
//    static constexpr auto Poprange0 = 6494720;

  public:
    FesXms204() : Sapphire::ScriptAPI::EventScript( 67914 ){}; 
    ~FesXms204() = default; 

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
        Scene00008( player );
        break;
      }
      case 255:
      {
        Scene00009( player );
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

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
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
      player.updateQuest( getId(), 1 );
    };

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
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

    player.playScene( getId(), 9, NONE, callback );
  }

};

EXPOSE_SCRIPT( FesXms204 );
