// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: JobRel400_02379
// Quest Name:  Future Proof
// Quest ID: 67915
// Start NPC: 1016135
// End NPC: 1016135

using namespace Sapphire;

class JobRel400 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL

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
//    static constexpr auto Actor1 = 1018189;
//    static constexpr auto AstMain = 15249;
//    static constexpr auto BardMain = 15241;
//    static constexpr auto BlackMain = 15246;
//    static constexpr auto CompJobrel400 = 67915;
//    static constexpr auto DarkMain = 15243;
//    static constexpr auto DragoonMain = 15240;
//    static constexpr auto ImageAnima345Start = 453;
//    static constexpr auto Item0 = 2002022;
//    static constexpr auto Item1 = 2002026;
//    static constexpr auto LcutAction1 = 4263;
//    static constexpr auto LcutAction2 = 990;
//    static constexpr auto LcutAction3 = 791;
//    static constexpr auto LcutAnimaGet = 4244;
//    static constexpr auto LcutBgmKosho = 102;
//    static constexpr auto LcutVfx1 = 241;
//    static constexpr auto LocActor01 = 1018225;
//    static constexpr auto LocActor02 = 1018226;
//    static constexpr auto LocActor03 = 1018339;
//    static constexpr auto LocBindAnima01 = 6490650;
//    static constexpr auto LocBindAnima02 = 6490651;
//    static constexpr auto LocBindGerolt = 6084432;
//    static constexpr auto LocBukibgm = 86;
//    static constexpr auto LocDepopAction = 4231;
//    static constexpr auto LocEobj01 = 2007538;
//    static constexpr auto LocEobj02 = 2007539;
//    static constexpr auto LocEventActionHappy = 953;
//    static constexpr auto LocEventArms = 1041;
//    static constexpr auto LocEventSigth = 4229;
//    static constexpr auto LocHideAction = 1078;
//    static constexpr auto LocIdleTalk = 799;
//    static constexpr auto LocMemai = 4260;
//    static constexpr auto LocPopAction = 4230;
//    static constexpr auto LocSeirei = 1016789;
//    static constexpr auto LocSe01 = 90;
//    static constexpr auto LocSe02 = 136;
//    static constexpr auto LogMsgEventCancel = 1319;
//    static constexpr auto MachinMain = 15244;
//    static constexpr auto MonkMain = 15238;
//    static constexpr auto NinjaMain = 15242;
//    static constexpr auto PaladinMain = 15237;
//    static constexpr auto PaladinSub = 15250;
//    static constexpr auto Ritem0 = 16064;
//    static constexpr auto ScholarMain = 15248;
//    static constexpr auto SummonMain = 15247;
//    static constexpr auto WahiteMain = 15245;
//    static constexpr auto WarriorMain = 15239;

  public:
    JobRel400() : Sapphire::ScriptAPI::EventScript( 67915 ){}; 
    ~JobRel400() = default; 

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
        Scene00003( player );
        break;
      }
      case 4:
      {
        Scene00004( player );
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
      player.updateQuest( getId(), 3 );
    };

    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 4 );
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
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 5, NONE, callback );
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

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 7, NONE, callback );
  }

};

EXPOSE_SCRIPT( JobRel400 );
