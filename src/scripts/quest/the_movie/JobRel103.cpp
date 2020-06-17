// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: JobRel103_02214
// Quest Name:  Coming into Its Own
// Quest ID: 67750
// Start NPC: 1016135
// End NPC: 1016136

using namespace Sapphire;

class JobRel103 : public Sapphire::ScriptAPI::EventScript
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
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineFacialComeon = 608;
//    static constexpr auto Actor0 = 1016135;
//    static constexpr auto Actor1 = 1016290;
//    static constexpr auto Actor2 = 1016136;
//    static constexpr auto AstMain = 13235;
//    static constexpr auto BardMain = 13227;
//    static constexpr auto BlackMain = 13232;
//    static constexpr auto CompJobrel103 = 67750;
//    static constexpr auto DarkMain = 13229;
//    static constexpr auto DragoonMain = 13226;
//    static constexpr auto EventArms = 1041;
//    static constexpr auto EventMigamaeru = 1022;
//    static constexpr auto LcutAction1 = 241;
//    static constexpr auto LcutAnimaGet = 4244;
//    static constexpr auto LocBindArdashir = 6084431;
//    static constexpr auto LocBindGerolt = 6084432;
//    static constexpr auto LocBukibgm = 86;
//    static constexpr auto LocEobjStone = 2006764;
//    static constexpr auto LocNohin = 990;
//    static constexpr auto LocSeRight = 91;
//    static constexpr auto MachinMain = 13230;
//    static constexpr auto MonkMain = 13224;
//    static constexpr auto Ncut01 = 1108;
//    static constexpr auto NinjaMain = 13228;
//    static constexpr auto PaladinMain = 13223;
//    static constexpr auto PaladinSub = 13236;
//    static constexpr auto Ritem0 = 13577;
//    static constexpr auto Ritem1 = 13578;
//    static constexpr auto Ritem2 = 13579;
//    static constexpr auto Ritem3 = 13580;
//    static constexpr auto ScholarMain = 13234;
//    static constexpr auto SummonMain = 13233;
//    static constexpr auto WahiteMain = 13231;
//    static constexpr auto WarriorMain = 13225;

  public:
    JobRel103() : Sapphire::ScriptAPI::EventScript( 67750 ){}; 
    ~JobRel103() = default; 

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
      case 3:
      {
        Scene00004( player );
        break;
      }
      case 4:
      {
        Scene00005( player );
        break;
      }
      case 5:
      {
        Scene00006( player );
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

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 3 );
    };

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 4 );
    };

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 5 );
    };

    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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

};

EXPOSE_SCRIPT( JobRel103 );
