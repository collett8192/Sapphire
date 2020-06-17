// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ChrHdb731_03094
// Quest Name: In the Eye of the Hingan
// Quest ID: 68630
// Start NPC: 1024708
// End NPC: 1025893

using namespace Sapphire;

class ChrHdb731 : public Sapphire::ScriptAPI::EventScript
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
//      Seq3 = 3,
//      Seq4 = 4,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1024708;
//    static constexpr auto Actor1 = 1025885;
//    static constexpr auto Actor10 = 1025893;
//    static constexpr auto Actor11 = 1025894;
//    static constexpr auto Actor12 = 1025895;
//    static constexpr auto Actor2 = 1024355;
//    static constexpr auto Actor3 = 1025886;
//    static constexpr auto Actor4 = 1025887;
//    static constexpr auto Actor5 = 1025888;
//    static constexpr auto Actor6 = 1025889;
//    static constexpr auto Actor7 = 1025890;
//    static constexpr auto Actor8 = 1025891;
//    static constexpr auto Actor9 = 1025892;
//    static constexpr auto BindActor03 = 7447448;
//    static constexpr auto BindActor04 = 7447462;
//    static constexpr auto BindActor05 = 7447463;
//    static constexpr auto BindActor06 = 7447466;
//    static constexpr auto BindActor07 = 7447471;
//    static constexpr auto CutSceneN01 = 1791;
//    static constexpr auto InstanceContents01 = 57;
//    static constexpr auto LocAction01 = 1012;
//    static constexpr auto LocAction02 = 1025;
//    static constexpr auto LocAction03 = 1028;
//    static constexpr auto LocAction04 = 1029;
//    static constexpr auto LocAction05 = 1030;
//    static constexpr auto LocAction06 = 4256;
//    static constexpr auto LocAction10 = 624;
//    static constexpr auto LocAction12 = 6228;
//    static constexpr auto LocActor01 = 1023870;
//    static constexpr auto LocActor02 = 1019761;
//    static constexpr auto LocActor03 = 1005501;
//    static constexpr auto LocActor04 = 1025672;
//    static constexpr auto LocActor05 = 1025671;
//    static constexpr auto LocActor06 = 1025674;
//    static constexpr auto LocActor07 = 1025668;
//    static constexpr auto LocActor08 = 1008264;
//    static constexpr auto LocActor09 = 1019763;
//    static constexpr auto LocBgm01 = 191;
//    static constexpr auto LocBgm02 = 465;
//    static constexpr auto LocEquip0 = 24;
//    static constexpr auto LocEquip1 = 25;
//    static constexpr auto LocIdle01 = 5556;
//    static constexpr auto LocIdle02 = 4322;
//    static constexpr auto LocIdle03 = 827;
//    static constexpr auto LocPosMove0 = 7516501;
//    static constexpr auto LocSe01 = 39;
//    static constexpr auto LocSe02 = 40;
//    static constexpr auto Poprange0 = 7447474;

  public:
    ChrHdb731() : Sapphire::ScriptAPI::EventScript( 68630 ){}; 
    ~ChrHdb731() = default; 

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
        Scene00015( player );
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
      Scene00005( player );
    };

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
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

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };

    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
      Scene00012( player );
    };

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };

    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };

    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
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

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00017( player );
    };

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 18, NONE, callback );
  }

};

EXPOSE_SCRIPT( ChrHdb731 );
