// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: StmBdi301_03187
// Quest Name: The Path of Most Resistance
// Quest ID: 68723
// Start NPC: 1024149
// End NPC: 1026970

using namespace Sapphire;

class StmBdi301 : public Sapphire::ScriptAPI::EventScript
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
//      BindMonSeq4 = _MON_SEQ4,
//      LocMikotoSeq3 = MIKOTO_SEQ3,
//      Seq0 = 0,
//      Seq1 = 1,
//      Seq2 = 2,
//      Seq3 = 3,
//      Seq4 = 4,
//      Seq5 = 5,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineMayu = 6228;
//    static constexpr auto ActionTimelineNigawara = 6229;
//    static constexpr auto Actor0 = 1024149;
//    static constexpr auto Actor1 = 1024157;
//    static constexpr auto Actor2 = 1024155;
//    static constexpr auto Actor3 = 1026968;
//    static constexpr auto Actor4 = 1027060;
//    static constexpr auto Actor5 = 1026969;
//    static constexpr auto Actor6 = 1026970;
//    static constexpr auto Actor7 = 1026971;
//    static constexpr auto Actor8 = 1026972;
//    static constexpr auto BindHurdySeq3 = 7760046;
//    static constexpr auto BindJenomisSeq3 = 7760044;
//    static constexpr auto BindMonbSeq3 = 7767439;
//    static constexpr auto BindMonSeq4 = 7745116;
//    static constexpr auto BindRamzaSeq3 = 7747162;
//    static constexpr auto BindRinaSeq3 = 7760044;
//    static constexpr auto CompStmbde106 = 68684;
//    static constexpr auto EventActionKashige = 958;
//    static constexpr auto EventActionManzoku = 1023;
//    static constexpr auto EventActionZannen = 1024;
//    static constexpr auto EventTrouble = 944;
//    static constexpr auto LocAction3 = 954;
//    static constexpr auto LocBgm007 = 616;
//    static constexpr auto LocBgmBackgroundStory = 514;
//    static constexpr auto LocBgmHeroTheme = 512;
//    static constexpr auto LocBgmPlayerCreation = 511;
//    static constexpr auto LocBgmSaintAjorasTheme = 615;
//    static constexpr auto LocJakuemi = 6215;
//    static constexpr auto LocKanmu = 6216;
//    static constexpr auto LocKomaru = 625;
//    static constexpr auto LocLeftTrun = 4257;
//    static constexpr auto LocMedlitate = 6227;
//    static constexpr auto LocMikotoNon = 1025498;
//    static constexpr auto LocMikotoSeq3 = 7848803;
//    static constexpr auto LocMikotoWep = 1027204;
//    static constexpr auto LocMonb = 1025496;
//    static constexpr auto LocMotHaxtu = 5596;
//    static constexpr auto LocRightTrun = 4256;
//    static constexpr auto NcutStmbdi02010 = 1896;
//    static constexpr auto NcutStmbdi02020 = 1897;
//    static constexpr auto NcutStmbdi02030 = 1898;
//    static constexpr auto Poprange0 = 7745080;
//    static constexpr auto Territorytype0 = 735;

  public:
    StmBdi301() : Sapphire::ScriptAPI::EventScript( 68723 ){}; 
    ~StmBdi301() = default; 

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

    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };

    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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

    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 15, NONE, callback );
  }

};

EXPOSE_SCRIPT( StmBdi301 );
