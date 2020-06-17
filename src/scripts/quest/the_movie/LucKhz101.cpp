// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: LucKhz101_03839
// Quest Name: Shadow over the Orphanage
// Quest ID: 69375
// Start NPC: 1032802
// End NPC: 1032802

using namespace Sapphire;

class LucKhz101 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
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
//      TextLuckhz10103839Rasequin000020 = _LUCKHZ101_03839_RASEQUIN_000_020,
//      TextLuckhz10103839Rasequin000021 = _LUCKHZ101_03839_RASEQUIN_000_021,
//      TextLuckhz10103839Rasequin000040 = _LUCKHZ101_03839_RASEQUIN_000_040,
//      TextLuckhz10103839Rasequin000041 = _LUCKHZ101_03839_RASEQUIN_000_041,
//      TextLuckhz10103839Rasequin000042 = _LUCKHZ101_03839_RASEQUIN_000_042,
//      TextLuckhz10103839Rasequin000046 = _LUCKHZ101_03839_RASEQUIN_000_046,
//      TextLuckhz10103839Rasequin000047 = _LUCKHZ101_03839_RASEQUIN_000_047,
//      TextLuckhz10103839Rasequin000048 = _LUCKHZ101_03839_RASEQUIN_000_048,
//      TextLuckhz10103839Rasequin000049 = _LUCKHZ101_03839_RASEQUIN_000_049,
//      TextLuckhz10103839Rasequin000050 = _LUCKHZ101_03839_RASEQUIN_000_050,
//      TextLuckhz10103839Rasequin000051 = _LUCKHZ101_03839_RASEQUIN_000_051,
//      TextLuckhz10103839Rasequin000053 = _LUCKHZ101_03839_RASEQUIN_000_053,
//      TextLuckhz10103839Rasequin000054 = _LUCKHZ101_03839_RASEQUIN_000_054,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1032802;
//    static constexpr auto Actor1 = 1032803;
//    static constexpr auto Actor2 = 1032805;
//    static constexpr auto Actor3 = 1032806;
//    static constexpr auto Actor4 = 1032804;
//    static constexpr auto Actor5 = 1032807;
//    static constexpr auto Actor6 = 1032808;
//    static constexpr auto Actor7 = 1032809;
//    static constexpr auto BindActor0 = 8267160;
//    static constexpr auto BindActor1 = 8267164;
//    static constexpr auto BindActor2 = 8267165;
//    static constexpr auto LocAction0 = 4301;
//    static constexpr auto LocActor0 = 1032968;
//    static constexpr auto LocActor1 = 1032796;
//    static constexpr auto LocActor2 = 1032797;
//    static constexpr auto LocActor3 = 1032817;
//    static constexpr auto LocEnpc0 = 1033519;
//    static constexpr auto LocEnpc1 = 1033520;
//    static constexpr auto LocEnpc2 = 1033524;
//    static constexpr auto LocEnpc3 = 1033525;
//    static constexpr auto LocPosActor0 = 8313150;

  public:
    LucKhz101() : Sapphire::ScriptAPI::EventScript( 69375 ){}; 
    ~LucKhz101() = default; 

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
        Scene00012( player );
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

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
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
      Scene00007( player );
    };

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
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
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
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

    player.playScene( getId(), 12, NONE, callback );
  }

};

EXPOSE_SCRIPT( LucKhz101 );
