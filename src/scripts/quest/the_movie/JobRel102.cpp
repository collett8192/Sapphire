// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: JobRel102_02213
// Quest Name:  Toughening Up
// Quest ID: 67749
// Start NPC: 1016135
// End NPC: 1016135

using namespace Sapphire;

class JobRel102 : public Sapphire::ScriptAPI::EventScript
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
//      Seq10 = 10,
//      Seq11 = 11,
//      Seq12 = 12,
//      Seq13 = 13,
//      Seq2 = 2,
//      Seq3 = 3,
//      Seq4 = 4,
//      Seq5 = 5,
//      Seq6 = 6,
//      Seq7 = 7,
//      Seq8 = 8,
//      Seq9 = 9,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1016135;
//    static constexpr auto Actor1 = 5010000;
//    static constexpr auto Actor2 = 1016517;
//    static constexpr auto Actor3 = 1016518;
//    static constexpr auto Actor4 = 1016519;
//    static constexpr auto AstMain = 13609;
//    static constexpr auto BardMain = 13601;
//    static constexpr auto BlackMain = 13606;
//    static constexpr auto DarkMain = 13603;
//    static constexpr auto DragoonMain = 13600;
//    static constexpr auto EventArms = 1041;
//    static constexpr auto EventMigamaeru = 1022;
//    static constexpr auto Instancedungeon0 = 27;
//    static constexpr auto Instancedungeon1 = 28;
//    static constexpr auto Instancedungeon2 = 26;
//    static constexpr auto Instancedungeon3 = 32;
//    static constexpr auto Instancedungeon4 = 30;
//    static constexpr auto Instancedungeon5 = 29;
//    static constexpr auto Instancedungeon6 = 36;
//    static constexpr auto Instancedungeon7 = 37;
//    static constexpr auto Instancedungeon8 = 39;
//    static constexpr auto Instancedungeon9 = 34;
//    static constexpr auto Jobrel102Comp = 67749;
//    static constexpr auto LcutAction1 = 241;
//    static constexpr auto LcutAnimaGet = 4244;
//    static constexpr auto LcutVfx1 = 241;
//    static constexpr auto LocBackCameraKyoko = 6149216;
//    static constexpr auto LocBindGerolt = 6084432;
//    static constexpr auto LocBukibgm = 86;
//    static constexpr auto LocDepopAction = 4231;
//    static constexpr auto LocHideAction = 1078;
//    static constexpr auto LocMakerPcF1F3 = 6149005;
//    static constexpr auto LocMakerPcR2T2 = 6149004;
//    static constexpr auto LocPopAction = 4230;
//    static constexpr auto LocSaikutuBgm = 105;
//    static constexpr auto LocSeirei = 1016291;
//    static constexpr auto LocSeRight = 91;
//    static constexpr auto MachinMain = 13604;
//    static constexpr auto MonkMain = 13598;
//    static constexpr auto NinjaMain = 13602;
//    static constexpr auto PaladinMain = 13597;
//    static constexpr auto PaladinSub = 13610;
//    static constexpr auto Poprange0 = 6164797;
//    static constexpr auto Poprange1 = 6112292;
//    static constexpr auto Poprange2 = 6112298;
//    static constexpr auto ScholarMain = 13608;
//    static constexpr auto SummonMain = 13607;
//    static constexpr auto WahiteMain = 13605;
//    static constexpr auto WarriorMain = 13599;

  public:
    JobRel102() : Sapphire::ScriptAPI::EventScript( 67749 ){}; 
    ~JobRel102() = default; 

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
      case 2:
      {
        Scene00002( player );
        break;
      }
      case 255:
      {
        Scene00006( player );
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
      player.updateQuest( getId(), 2 );
    };

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };

    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
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

    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( JobRel102 );
