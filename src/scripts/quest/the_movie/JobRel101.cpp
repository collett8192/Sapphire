// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: JobRel101_02212
// Quest Name:  Soul without Life
// Quest ID: 67748
// Start NPC: 1016135
// End NPC: 1016135

using namespace Sapphire;

class JobRel101 : public Sapphire::ScriptAPI::EventScript
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
//      Seq2 = 2,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1016135;
//    static constexpr auto Actor1 = 1001304;
//    static constexpr auto Actor2 = 1016289;
//    static constexpr auto AstMain = 13623;
//    static constexpr auto BardMain = 13615;
//    static constexpr auto BlackMain = 13620;
//    static constexpr auto DarkMain = 13617;
//    static constexpr auto DragoonMain = 13614;
//    static constexpr auto EventArms = 1041;
//    static constexpr auto EventBaseSitPose1 = 1065;
//    static constexpr auto LcutAction1 = 241;
//    static constexpr auto LcutAnimaGet = 4244;
//    static constexpr auto LcutVfx1 = 241;
//    static constexpr auto LocActionAp = 745;
//    static constexpr auto LocActionThink = 589;
//    static constexpr auto LocActionWara = 651;
//    static constexpr auto LocBindGerolt = 6084432;
//    static constexpr auto LocBukibgm = 86;
//    static constexpr auto LocChohatuFace = 608;
//    static constexpr auto LocEobj = 2006758;
//    static constexpr auto LocEobjStone = 2006764;
//    static constexpr auto LocIbaruFace = 607;
//    static constexpr auto LocNohin = 990;
//    static constexpr auto LocQuestcomp = 67748;
//    static constexpr auto LocSeRight = 91;
//    static constexpr auto MachinMain = 13618;
//    static constexpr auto MonkMain = 13612;
//    static constexpr auto NinjaMain = 13616;
//    static constexpr auto PaladinMain = 13611;
//    static constexpr auto PaladinSub = 13624;
//    static constexpr auto Ritem0 = 13575;
//    static constexpr auto Ritem1 = 13576;
//    static constexpr auto ScholarMain = 13622;
//    static constexpr auto SummonMain = 13621;
//    static constexpr auto WahiteMain = 13619;
//    static constexpr auto WarriorMain = 13613;

  public:
    JobRel101() : Sapphire::ScriptAPI::EventScript( 67748 ){}; 
    ~JobRel101() = default; 

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
      Scene00003( player );
    };

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
      if( result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
    };

    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( JobRel101 );
