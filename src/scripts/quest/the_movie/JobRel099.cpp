// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: JobRel099_02287
// Quest Name: The Vital Title
// Quest ID: 67823
// Start NPC: 1008948
// End NPC: 1008948

using namespace Sapphire;

class JobRel099 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1008948;
//    static constexpr auto Actor1 = 1003075;
//    static constexpr auto BindActor0 = 4697909;
//    static constexpr auto BindActor1 = 4678141;
//    static constexpr auto LcutAction0 = 827;
//    static constexpr auto LcutAction1 = 828;
//    static constexpr auto LcutAction2 = 1091;
//    static constexpr auto LcutAction3 = 990;
//    static constexpr auto LcutAction4 = 1039;
//    static constexpr auto LcutActor0 = 1011792;
//    static constexpr auto LcutBgm0 = 100;
//    static constexpr auto LcutEobj0 = 2005235;
//    static constexpr auto LcutPos0 = 5674415;
//    static constexpr auto LcutPos1 = 5674418;
//    static constexpr auto LcutPos2 = 4311940;
//    static constexpr auto LcutPos3 = 5764983;
//    static constexpr auto LcutSe0 = 72;
//    static constexpr auto LcutSe1 = 80;
//    static constexpr auto ReplicaBard = 12160;
//    static constexpr auto ReplicaBlack = 12187;
//    static constexpr auto ReplicaDragon = 12151;
//    static constexpr auto ReplicaKnightMain = 12124;
//    static constexpr auto ReplicaKnightSub = 12213;
//    static constexpr auto ReplicaMonk = 12133;
//    static constexpr auto ReplicaNinja = 12169;
//    static constexpr auto ReplicaScholar = 12205;
//    static constexpr auto ReplicaSummoner = 12196;
//    static constexpr auto ReplicaWarrior = 12142;
//    static constexpr auto ReplicaWhite = 12178;
//    static constexpr auto Screenimage0 = 275;

  public:
    JobRel099() : Sapphire::ScriptAPI::EventScript( 67823 ){}; 
    ~JobRel099() = default; 

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
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
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

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 5, NONE, callback );
  }

};

EXPOSE_SCRIPT( JobRel099 );
