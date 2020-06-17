// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: FesPdy602_03851
// Quest Name: A Guest to Impress
// Quest ID: 69387
// Start NPC: 1032996
// End NPC: 1032996

using namespace Sapphire;

class FesPdy602 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1032996;
//    static constexpr auto Actor1 = 1032993;
//    static constexpr auto BindActor0 = 8320505;
//    static constexpr auto LocAction01 = 1012;
//    static constexpr auto LocActor0 = 1032999;
//    static constexpr auto LocActor1 = 1033001;
//    static constexpr auto LocActor10 = 1020991;
//    static constexpr auto LocActor11 = 1014554;
//    static constexpr auto LocActor12 = 1033015;
//    static constexpr auto LocActor13 = 1033002;
//    static constexpr auto LocActor14 = 1033003;
//    static constexpr auto LocActor15 = 1033004;
//    static constexpr auto LocActor16 = 1033018;
//    static constexpr auto LocActor17 = 1033019;
//    static constexpr auto LocActor18 = 1033020;
//    static constexpr auto LocActor19 = 1033034;
//    static constexpr auto LocActor2 = 1033009;
//    static constexpr auto LocActor20 = 1033035;
//    static constexpr auto LocActor21 = 1033260;
//    static constexpr auto LocActor22 = 1033261;
//    static constexpr auto LocActor3 = 1033010;
//    static constexpr auto LocActor4 = 1033011;
//    static constexpr auto LocActor5 = 1033012;
//    static constexpr auto LocActor6 = 1033013;
//    static constexpr auto LocActor7 = 1033014;
//    static constexpr auto LocActor8 = 1022448;
//    static constexpr auto LocActor9 = 1005139;
//    static constexpr auto LocBgm01 = 191;
//    static constexpr auto LocIdle01 = 5556;
//    static constexpr auto LocLevelCutPos0 = 8333565;
//    static constexpr auto LocLevelCutPos1 = 8336345;
//    static constexpr auto QstCompChk1 = 69387;
//    static constexpr auto QstCompChk10 = 68620;
//    static constexpr auto QstCompChk2 = 67913;
//    static constexpr auto QstCompChk3 = 66746;
//    static constexpr auto QstCompChk4 = 67354;
//    static constexpr auto QstCompChk5 = 68287;
//    static constexpr auto QstCompChk6 = 65963;
//    static constexpr auto QstCompChk7 = 67167;
//    static constexpr auto QstCompChk8 = 67757;
//    static constexpr auto QstCompChk9 = 67935;

  public:
    FesPdy602() : Sapphire::ScriptAPI::EventScript( 69387 ){}; 
    ~FesPdy602() = default; 

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

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
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

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 6, NONE, callback );
  }

};

EXPOSE_SCRIPT( FesPdy602 );
