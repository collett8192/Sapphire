// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: JobPld700_02575
// Quest Name: Raising the Sword
// Quest ID: 68111
// Start NPC: 1001739
// End NPC: 1001739

using namespace Sapphire;

class JobPld700 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1001739;
//    static constexpr auto Actor1 = 1021271;
//    static constexpr auto Actor2 = 1021384;
//    static constexpr auto Actor3 = 1021385;
//    static constexpr auto Actor4 = 1023883;
//    static constexpr auto Eobject0 = 2008186;
//    static constexpr auto Eventaction0 = 1;
//    static constexpr auto JobstoneModel = 1;
//    static constexpr auto LocActSup01 = 5473;
//    static constexpr auto LocBgmOdayaka01 = 400;
//    static constexpr auto LocEnpcAdri01 = 1021175;
//    static constexpr auto LocEnpcAldis01 = 1022449;
//    static constexpr auto LocEnpcAldis02 = 1004301;
//    static constexpr auto LocEnpcAnd01 = 1014558;
//    static constexpr auto LocEnpcBoy01 = 1023892;
//    static constexpr auto LocEnpcBro01 = 1005175;
//    static constexpr auto LocEnpcCont01 = 1022396;
//    static constexpr auto LocEnpcDour01 = 1009430;
//    static constexpr auto LocEnpcFran01 = 1022397;
//    static constexpr auto LocEnpcJenl01 = 1014472;
//    static constexpr auto LocEnpcMylla01 = 1020991;
//    static constexpr auto LocEnpcNanamo01 = 1022448;
//    static constexpr auto LocEnpcPapa01 = 1014471;
//    static constexpr auto LocLevelAldis01 = 6850146;
//    static constexpr auto LocLevelBoy01 = 7022298;
//    static constexpr auto LocLevelColo01 = 6906398;
//    static constexpr auto LocLevelComm01 = 6905339;
//    static constexpr auto LocLevelDour01 = 6850148;
//    static constexpr auto LocSeKansei01 = 142;
//    static constexpr auto LocSeZawa01 = 124;
//    static constexpr auto Ncut01 = 1507;
//    static constexpr auto Questbattle0 = 5018;
//    static constexpr auto Territorytype0 = 706;
//    static constexpr auto Territorytype1 = 131;
//    static constexpr auto WsGetAction = 5501;
//    static constexpr auto WsGetLog = 5351;
//    static constexpr auto WsGetSkill = 7385;
//    static constexpr auto WsGetVfx1 = 408;

  public:
    JobPld700() : Sapphire::ScriptAPI::EventScript( 68111 ){}; 
    ~JobPld700() = default; 

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
        player.sendUrgent( "This quest contains at least one quest battle, " );
        player.sendUrgent( "which has a high change to break the script and get stuck." );
        player.sendUrgent( "Use \"//gm quest sequence <questId> 255\" to skip broken scenes."); 
        player.sendUrgent( "### Hit NO when asked to enter quest battle ###" );
        Scene00000( player );
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
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
      Scene00010( player );
    };

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 11, NONE, callback );
  }

};

EXPOSE_SCRIPT( JobPld700 );
