// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: JobRel510_02398
// Quest Name: Body and Soul
// Quest ID: 67934
// Start NPC: 1019638
// End NPC: 1016135

using namespace Sapphire;

class JobRel510 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1019638;
//    static constexpr auto Actor1 = 1013713;
//    static constexpr auto Actor2 = 1016135;
//    static constexpr auto AnimaCampaign2End = 478;
//    static constexpr auto LcutBgm3 = 86;
//    static constexpr auto LcutBgmKosho = 102;
//    static constexpr auto LocBindAl = 6084431;
//    static constexpr auto LocBindGerolt = 6084432;
//    static constexpr auto LocDepopAction = 4231;
//    static constexpr auto LocEventActionHappy = 953;
//    static constexpr auto LocEventArms = 1041;
//    static constexpr auto LocEventMigamaeru = 1022;
//    static constexpr auto LocEventSigth = 4229;
//    static constexpr auto LocFaceAkunin = 622;
//    static constexpr auto LocHideAction = 1078;
//    static constexpr auto LocMemai = 4260;
//    static constexpr auto LocPopAction = 4230;
//    static constexpr auto LocRowena = 1018496;
//    static constexpr auto LocSaikutuBgm = 105;
//    static constexpr auto LocSeirei = 1016789;
//    static constexpr auto LocSeirei = 1018495;
//    static constexpr auto LocStopCall = 4255;

  public:
    JobRel510() : Sapphire::ScriptAPI::EventScript( 67934 ){}; 
    ~JobRel510() = default; 

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
      Scene00002( player );
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
      Scene00004( player );
    };

    player.playScene( getId(), 3, NONE, callback );
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

    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( JobRel510 );
