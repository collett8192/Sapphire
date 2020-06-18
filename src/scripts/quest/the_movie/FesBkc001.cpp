// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: FesBkc001_03158
// Quest Name: The Man in Black
// Quest ID: 68694
// Start NPC: 1026849
// End NPC: 1026849

using namespace Sapphire;

class FesBkc001 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto ActionTimelineEventLookBackLeft = 4257;
//    static constexpr auto ActionTimelineEventLookBackRight = 4256;
//    static constexpr auto ActionTimelineEventPerceive = 5596;
//    static constexpr auto ActionTimelineStopCall = 4255;
//    static constexpr auto Actor0 = 1026849;
//    static constexpr auto Actor1 = 5010000;
//    static constexpr auto Actor2 = 1026916;
//    static constexpr auto Actor3 = 1026913;
//    static constexpr auto Actor4 = 1026914;
//    static constexpr auto Actor5 = 1026915;
//    static constexpr auto Actor6 = 1026917;
//    static constexpr auto Actor7 = 1026850;
//    static constexpr auto Actor8 = 1026851;
//    static constexpr auto Actor9 = 1026866;
//    static constexpr auto BgmDaemons = 608;
//    static constexpr auto BgmHammerhead = 605;
//    static constexpr auto BgmRelax = 607;
//    static constexpr auto BgmSafeHeaven = 610;
//    static constexpr auto Eobject0 = 2009661;
//    static constexpr auto Eobject1 = 2009662;
//    static constexpr auto Eventaction0 = 50;
//    static constexpr auto Eventaction1 = 12;
//    static constexpr auto Fate0 = 1409;
//    static constexpr auto LocBkcCar = 1026847;
//    static constexpr auto LocBkcCid = 1003855;
//    static constexpr auto LocBkcGi = 1026873;
//    static constexpr auto LocBkcGi02 = 1028431;
//    static constexpr auto LocBkcGiMob1 = 1026874;
//    static constexpr auto LocBkcGiMob2 = 1026912;
//    static constexpr auto LocBkcMan = 1027163;
//    static constexpr auto LocCamera001 = 7739041;
//    static constexpr auto LocCount = 812;
//    static constexpr auto LocHiza = 934;
//    static constexpr auto LocJakuemi = 6215;
//    static constexpr auto LocKanmu = 6216;
//    static constexpr auto LocKipi = 1026963;
//    static constexpr auto LocKomaru = 625;
//    static constexpr auto LocKyoro = 5522;
//    static constexpr auto LocMeiso = 6227;
//    static constexpr auto LocMemo = 1043;
//    static constexpr auto LocNigawa = 6229;
//    static constexpr auto LocPosGi = 7732451;
//    static constexpr auto LocPosPc = 7732449;
//    static constexpr auto LocPosPc002 = 7732863;
//    static constexpr auto NcutFesbkc00110 = 1914;
//    static constexpr auto Poprange0 = 7725917;
//    static constexpr auto Poprange1 = 7848801;
//    static constexpr auto QstFeskgt003 = 66691;
//    static constexpr auto ScreenimageAccepted = 707;
//    static constexpr auto ScreenimageComplete = 708;

  public:
    FesBkc001() : Sapphire::ScriptAPI::EventScript( 68694 ){}; 
    ~FesBkc001() = default; 

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
      Scene00012( player );
    };

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
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
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
    };

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 17, NONE, callback );
  }

};

EXPOSE_SCRIPT( FesBkc001 );
