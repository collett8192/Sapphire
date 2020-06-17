// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: JobRel300_02328
// Quest Name:  A Dream Fulfilled
// Quest ID: 67864
// Start NPC: 1016135
// End NPC: 1016135

using namespace Sapphire;

class JobRel300 : public Sapphire::ScriptAPI::EventScript
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
//      Seq2 = 2,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1016135;
//    static constexpr auto Actor1 = 1017108;
//    static constexpr auto Actor2 = 1017529;
//    static constexpr auto AnimaGrass = 2001994;
//    static constexpr auto AstMain = 15235;
//    static constexpr auto BardMain = 15227;
//    static constexpr auto BlackMain = 15232;
//    static constexpr auto CompJobrel300 = 67864;
//    static constexpr auto DarkMain = 15229;
//    static constexpr auto DragoonMain = 15226;
//    static constexpr auto EventBaseKneeSuffering = 936;
//    static constexpr auto LcutAction1 = 241;
//    static constexpr auto LcutAnimaGet = 4244;
//    static constexpr auto LcutBgmKosho = 102;
//    static constexpr auto LcutVfx1 = 241;
//    static constexpr auto LocArdashir = 1016243;
//    static constexpr auto LocArnott = 1017668;
//    static constexpr auto LocBindDaia = 6387804;
//    static constexpr auto LocBindGerolt = 6084432;
//    static constexpr auto LocBukibgm = 86;
//    static constexpr auto LocDepopAction = 4231;
//    static constexpr auto LocEobjStone = 2006764;
//    static constexpr auto LocEventActionHappy = 953;
//    static constexpr auto LocEventActionWink = 621;
//    static constexpr auto LocEventArms = 1041;
//    static constexpr auto LocEventMigamaeru = 1022;
//    static constexpr auto LocEventSigth = 4229;
//    static constexpr auto LocHideAction = 1078;
//    static constexpr auto LocKakun = 1017637;
//    static constexpr auto LocMakerUran = 6404846;
//    static constexpr auto LocMemai = 4260;
//    static constexpr auto LocNohin = 990;
//    static constexpr auto LocPopAction = 4230;
//    static constexpr auto LocSeirei = 1016789;
//    static constexpr auto LocSeRight = 91;
//    static constexpr auto LocStopCall = 4255;
//    static constexpr auto LogMsgEvent = 2031;
//    static constexpr auto MachinMain = 15230;
//    static constexpr auto MonkMain = 15224;
//    static constexpr auto NinjaMain = 15228;
//    static constexpr auto PaladinMain = 15223;
//    static constexpr auto PaladinSub = 15236;
//    static constexpr auto PlayDosa = 80;
//    static constexpr auto ScholarMain = 15234;
//    static constexpr auto SummonMain = 15233;
//    static constexpr auto UlanMemo = 2001993;
//    static constexpr auto WahiteMain = 15231;
//    static constexpr auto WarriorMain = 15225;

  public:
    JobRel300() : Sapphire::ScriptAPI::EventScript( 67864 ){}; 
    ~JobRel300() = default; 

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
        Scene00005( player );
        break;
      }
      case 255:
      {
        Scene00008( player );
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

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 3 );
    };

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };

    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };

    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
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

    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 9, NONE, callback );
  }

};

EXPOSE_SCRIPT( JobRel300 );
