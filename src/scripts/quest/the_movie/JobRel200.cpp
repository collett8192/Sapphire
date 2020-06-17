// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: JobRel200_02284
// Quest Name:  Finding Your Voice
// Quest ID: 67820
// Start NPC: 1016135
// End NPC: 1016135

using namespace Sapphire;

class JobRel200 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto ActionTimelineEventActionHappy = 953;
//    static constexpr auto ActionTimelineEventActionSympathy = 170;
//    static constexpr auto ActionTimelineEventEmoteNoAdd = 666;
//    static constexpr auto ActionTimelineEventLookBackRight = 4256;
//    static constexpr auto ActionTimelineEventPoseEmoteB01Start = 3127;
//    static constexpr auto ActionTimelineEventSigh = 4229;
//    static constexpr auto ActionTimelineEventSpeakShoutMiddle = 632;
//    static constexpr auto ActionTimelineFaceSurprised = 618;
//    static constexpr auto ActionTimelineFacialBossy = 607;
//    static constexpr auto ActionTimelineHummer = 4263;
//    static constexpr auto ActionTimelineStopCall = 4255;
//    static constexpr auto ActionTimelineYesStAdd = 672;
//    static constexpr auto Actor0 = 1016135;
//    static constexpr auto AstMain = 14882;
//    static constexpr auto BardMain = 14874;
//    static constexpr auto BlackMain = 14879;
//    static constexpr auto CompJobrel200 = 67820;
//    static constexpr auto DarkMain = 14876;
//    static constexpr auto DragoonMain = 14873;
//    static constexpr auto EventArms = 1041;
//    static constexpr auto EventMigamaeru = 1022;
//    static constexpr auto FacialAngryStrong = 610;
//    static constexpr auto LcutAnimaGet = 4244;
//    static constexpr auto LcutBgmKosho = 102;
//    static constexpr auto LcutVfx1 = 241;
//    static constexpr auto LocBindGerolt = 6084432;
//    static constexpr auto LocBukibgm = 86;
//    static constexpr auto LocDaragabuFukkou = 1017127;
//    static constexpr auto LocDepopAction = 4231;
//    static constexpr auto LocHideAction = 1078;
//    static constexpr auto LocMakerPcA2F2 = 6248264;
//    static constexpr auto LocNohin = 990;
//    static constexpr auto LocPopAction = 4230;
//    static constexpr auto LocSaikutuBgm = 105;
//    static constexpr auto LocSeirei = 1016291;
//    static constexpr auto LocSeirei = 1016789;
//    static constexpr auto LocSeEventOilRefers = 117;
//    static constexpr auto LocSeAetheryteExchange = 118;
//    static constexpr auto MachinMain = 14877;
//    static constexpr auto MonkMain = 14871;
//    static constexpr auto NinjaMain = 14875;
//    static constexpr auto PaladinMain = 14870;
//    static constexpr auto PaladinSub = 14883;
//    static constexpr auto Ritem0 = 14899;
//    static constexpr auto ScholarMain = 14881;
//    static constexpr auto SummonMain = 14880;
//    static constexpr auto WahiteMain = 14878;
//    static constexpr auto WarriorMain = 14872;

  public:
    JobRel200() : Sapphire::ScriptAPI::EventScript( 67820 ){}; 
    ~JobRel200() = default; 

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
        Scene00003( player );
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
      player.updateQuest( getId(), 255 );
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

EXPOSE_SCRIPT( JobRel200 );
