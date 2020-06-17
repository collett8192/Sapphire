// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: JobRel521_02404
// Quest Name:  Best Friends Forever
// Quest ID: 67940
// Start NPC: 1016135
// End NPC: 1016135

using namespace Sapphire;

class JobRel521 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL
    // GetQuestUI8CH

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      Seq2 = 2,
//      Seq3 = 3,
//      Seq4 = 4,
//      Seq5 = 5,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineEventActionSympathy = 170;
//    static constexpr auto ActionTimelineStopCall = 4255;
//    static constexpr auto Actor0 = 1016135;
//    static constexpr auto Actor1 = 5010000;
//    static constexpr auto CompJobrel521 = 67940;
//    static constexpr auto EventMigamaeru = 1022;
//    static constexpr auto Instancedungeon0 = 20004;
//    static constexpr auto Instancedungeon1 = 20006;
//    static constexpr auto Instancedungeon10 = 20041;
//    static constexpr auto Instancedungeon11 = 20043;
//    static constexpr auto Instancedungeon2 = 20005;
//    static constexpr auto Instancedungeon3 = 20011;
//    static constexpr auto Instancedungeon4 = 20017;
//    static constexpr auto Instancedungeon5 = 20022;
//    static constexpr auto Instancedungeon6 = 20024;
//    static constexpr auto Instancedungeon7 = 20031;
//    static constexpr auto Instancedungeon8 = 20033;
//    static constexpr auto Instancedungeon9 = 20037;
//    static constexpr auto LcutAnimaGet = 4244;
//    static constexpr auto LcutBgm3 = 86;
//    static constexpr auto LcutBgmKosho = 102;
//    static constexpr auto LcutVfx1 = 241;
//    static constexpr auto LocBindGerolt = 6084432;
//    static constexpr auto LocDepopAction = 4231;
//    static constexpr auto LocEobjKurobin = 2007635;
//    static constexpr auto LocEventActionHappy = 953;
//    static constexpr auto LocHideAction = 1078;
//    static constexpr auto LocMemai = 4260;
//    static constexpr auto LocNohin = 990;
//    static constexpr auto LocPopAction = 4230;
//    static constexpr auto LocSeirei = 1018495;
//    static constexpr auto LocSe02 = 136;
//    static constexpr auto LocSeHq = 90;
//    static constexpr auto LocSeKanadoko = 117;
//    static constexpr auto LocSeKoukan = 118;
//    static constexpr auto LogMsgEventCancel = 1319;
//    static constexpr auto Ritem0 = 16934;

  public:
    JobRel521() : Sapphire::ScriptAPI::EventScript( 67940 ){}; 
    ~JobRel521() = default; 

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
        Scene00003( player );
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
      player.updateQuest( getId(), 1 );
    };

    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 3, NONE, callback );
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

    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( JobRel521 );
