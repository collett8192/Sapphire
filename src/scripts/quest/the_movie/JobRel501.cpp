// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: JobRel501_02397
// Quest Name: Some Assembly Required
// Quest ID: 67933
// Start NPC: 1018340
// End NPC: 1018340

using namespace Sapphire;

class JobRel501 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1018340;
//    static constexpr auto AnimaSoulstoneStart = 479;
//    static constexpr auto LocAction01 = 1071;
//    static constexpr auto LocAction02 = 990;
//    static constexpr auto LocAction03 = 181;
//    static constexpr auto LocAction04 = 182;
//    static constexpr auto LocAction05 = 183;
//    static constexpr auto LocActor01 = 1016243;
//    static constexpr auto LocBgm01 = 101;
//    static constexpr auto LocBindArdashir = 6084431;
//    static constexpr auto LocEobj01 = 2007640;
//    static constexpr auto LocEobj02 = 2007641;
//    static constexpr auto LocSe01 = 80;
//    static constexpr auto LocSe02 = 120;
//    static constexpr auto LocSe03 = 138;
//    static constexpr auto LocSe04 = 139;
//    static constexpr auto QstCheckJobrel500 = 67932;
//    static constexpr auto QstCheckJobrel501 = 67933;
//    static constexpr auto Ritem0 = 16933;

  public:
    JobRel501() : Sapphire::ScriptAPI::EventScript( 67933 ){}; 
    ~JobRel501() = default; 

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
        Scene00002( player );
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
      player.updateQuest( getId(), 255 );
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
      if( result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
    };

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( JobRel501 );
