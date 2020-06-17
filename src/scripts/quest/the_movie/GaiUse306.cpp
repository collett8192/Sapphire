// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse306_01447
// Quest Name: Stories We Tell
// Quest ID: 66983
// Start NPC: 1009057
// End NPC: 1008579

using namespace Sapphire;

class GaiUse306 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineEventBaseSadOver = 924;
//    static constexpr auto ActionTimelineEventLink = 1002;
//    static constexpr auto ActionTimelineFacialCry = 612;
//    static constexpr auto ActionTimelineFacialSmile = 605;
//    static constexpr auto Actor0 = 1009057;
//    static constexpr auto Actor1 = 1008579;
//    static constexpr auto Actor2 = 1009089;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto LocActor0 = 1009238;
//    static constexpr auto LocActor1 = 2621120;
//    static constexpr auto LocActor2 = 1008175;
//    static constexpr auto LocSe01 = 42;
//    static constexpr auto Poprange0 = 4894865;
//    static constexpr auto QstCompChk01 = 67063;
//    static constexpr auto QstCompChk02 = 67064;
//    static constexpr auto QstCompChk03 = 67065;

  public:
    GaiUse306() : Sapphire::ScriptAPI::EventScript( 66983 ){}; 
    ~GaiUse306() = default; 

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
      if( result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
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

};

EXPOSE_SCRIPT( GaiUse306 );
