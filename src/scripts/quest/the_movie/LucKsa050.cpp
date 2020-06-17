// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: LucKsa050_03844
// Quest Name:  Fire in the Forge
// Quest ID: 69380
// Start NPC: 1032903
// End NPC: 1032903

using namespace Sapphire;

class LucKsa050 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1032903;
//    static constexpr auto Actor1 = 1032904;
//    static constexpr auto AstrologianWeapon = 30240;
//    static constexpr auto BardWeapon = 30232;
//    static constexpr auto BindActor01 = 8278611;
//    static constexpr auto BlackmageWeapon = 30237;
//    static constexpr auto DancerWeapon = 30244;
//    static constexpr auto DarkknightWeapon = 30234;
//    static constexpr auto DragoonWeapon = 30231;
//    static constexpr auto Eobject0 = 2011033;
//    static constexpr auto Eventaction0 = 11;
//    static constexpr auto GunbreakerWeapon = 30243;
//    static constexpr auto InvisActor01 = 1019063;
//    static constexpr auto Item0 = 2002994;
//    static constexpr auto LocAction01 = 5706;
//    static constexpr auto LocAction02 = 5665;
//    static constexpr auto LocAction03 = 241;
//    static constexpr auto LocActor01 = 1018496;
//    static constexpr auto LocActor02 = 1033045;
//    static constexpr auto LocSe01 = 90;
//    static constexpr auto LocVfx01 = 241;
//    static constexpr auto MachinistWeapon = 30235;
//    static constexpr auto MonkWeapon = 30229;
//    static constexpr auto MycWeaponStart = 872;
//    static constexpr auto NinjaWeapon = 30233;
//    static constexpr auto PaladinWeaponMain = 30228;
//    static constexpr auto PaladinWeaponSub = 30245;
//    static constexpr auto RedmageWeapon = 30242;
//    static constexpr auto RedmageWeaponOrb = 31;
//    static constexpr auto SamuraiWeapon = 30241;
//    static constexpr auto ScholarWeapon = 30239;
//    static constexpr auto SummonerWeapon = 30238;
//    static constexpr auto WarriorWeapon = 30230;
//    static constexpr auto WhitemageWeapon = 30236;

  public:
    LucKsa050() : Sapphire::ScriptAPI::EventScript( 69380 ){}; 
    ~LucKsa050() = default; 

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

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
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
      Scene00005( player );
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
      Scene00007( player );
    };

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 3 );
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

    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 10, NONE, callback );
  }

};

EXPOSE_SCRIPT( LucKsa050 );
