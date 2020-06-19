// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: BanAll240_03164
// Quest Name: What a Wonder-full World
// Quest ID: 68700
// Start NPC: 1026421
// End NPC: 1026426

using namespace Sapphire;

class BanAll240 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1026421;
//    static constexpr auto Actor1 = 1025601;
//    static constexpr auto Actor2 = 1026424;
//    static constexpr auto Actor3 = 1026425;
//    static constexpr auto Actor4 = 1019048;
//    static constexpr auto Actor5 = 1026607;
//    static constexpr auto Actor6 = 1026608;
//    static constexpr auto Actor7 = 1026426;
//    static constexpr auto Actor8 = 1026427;
//    static constexpr auto BindActor01 = 7631410;
//    static constexpr auto BindActor02 = 7631454;
//    static constexpr auto CutScene00 = 1871;
//    static constexpr auto CutScene01 = 1872;
//    static constexpr auto Eobject0 = 2009606;
//    static constexpr auto Eobject1 = 2009607;
//    static constexpr auto Eventaction0 = 12;
//    static constexpr auto Eventaction1 = 41;
//    static constexpr auto LocAction01 = 1002;
//    static constexpr auto LocAction02 = 953;
//    static constexpr auto LocAction03 = 954;
//    static constexpr auto LocAction04 = 982;
//    static constexpr auto LocAction05 = 945;
//    static constexpr auto LocAction06 = 6215;
//    static constexpr auto LocAction07 = 625;
//    static constexpr auto LocActor01 = 1024752;
//    static constexpr auto LocActor02 = 1026391;
//    static constexpr auto LocActor03 = 1026475;
//    static constexpr auto LocActor04 = 1025636;
//    static constexpr auto LocActor05 = 1025638;
//    static constexpr auto LocActor06 = 1024276;
//    static constexpr auto LocBgm0 = 458;
//    static constexpr auto LocSe01 = 42;
//    static constexpr auto LocSe02 = 71;
//    static constexpr auto LocSe03 = 80;
//    static constexpr auto LogMessage001 = 3230;
//    static constexpr auto Poprange0 = 7631450;
//    static constexpr auto Poprange1 = 7633819;
//    static constexpr auto Poprange2 = 7673127;
//    static constexpr auto QstCompChk00 = 68170;
//    static constexpr auto QstCompChk01 = 67009;
//    static constexpr auto QstCompChk02 = 67921;
//    static constexpr auto ScreenImageFriendRankup = 149;

  public:
    BanAll240() : Sapphire::ScriptAPI::EventScript( 68700 ){}; 
    ~BanAll240() = default; 

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
        Scene00009( player );
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
      Scene00004( player );
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

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };

    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };

    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
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

    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 17, NONE, callback );
  }

};

EXPOSE_SCRIPT( BanAll240 );
