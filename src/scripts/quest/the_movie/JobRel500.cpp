// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: JobRel500_02396
// Quest Name:  Born Again Anima
// Quest ID: 67932
// Start NPC: 1016135
// End NPC: 1016136

using namespace Sapphire;

class JobRel500 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL
    // GetQuestUI8CH
    // GetQuestUI8CL
    // GetQuestUI8DH

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
//    static constexpr auto ActionTimelineHummer = 4263;
//    static constexpr auto Actor0 = 1016135;
//    static constexpr auto Actor1 = 5010000;
//    static constexpr auto Actor2 = 1016136;
//    static constexpr auto Actor3 = 1018340;
//    static constexpr auto Actor4 = 1018445;
//    static constexpr auto CompJobrel500 = 67932;
//    static constexpr auto CutJobrel500 = 1352;
//    static constexpr auto Instancedungeon0 = 42;
//    static constexpr auto Instancedungeon1 = 47;
//    static constexpr auto Instancedungeon2 = 49;
//    static constexpr auto Item0 = 2002030;
//    static constexpr auto Item1 = 2002031;
//    static constexpr auto Item2 = 2002032;
//    static constexpr auto LocAction01 = 1071;
//    static constexpr auto LocAction02 = 181;
//    static constexpr auto LocAction03 = 182;
//    static constexpr auto LocActor01 = 1016243;
//    static constexpr auto LocBgm01 = 86;
//    static constexpr auto LocBindArdashir = 6084431;
//    static constexpr auto LocBindCertify = 6584301;
//    static constexpr auto LocBindGerolt = 6084432;
//    static constexpr auto LocBindProcess = 6532860;
//    static constexpr auto LocDepopAction = 4231;
//    static constexpr auto LocEobjNewstone = 2007618;
//    static constexpr auto LocEobjOldstone = 2006764;
//    static constexpr auto LocEventActionHappy = 953;
//    static constexpr auto LocEventArms = 1041;
//    static constexpr auto LocEventSigth = 4229;
//    static constexpr auto LocFaceNaku = 612;
//    static constexpr auto LocHideAction = 1078;
//    static constexpr auto LocKaooou = 4674;
//    static constexpr auto LocMemai = 4260;
//    static constexpr auto LocNohin = 990;
//    static constexpr auto LocPopAction = 4230;
//    static constexpr auto LocSeirei = 1016789;
//    static constexpr auto LocSeirei2 = 1019557;
//    static constexpr auto LocSe01 = 120;
//    static constexpr auto LocSeLb = 136;
//    static constexpr auto LocSeLbdragon = 141;
//    static constexpr auto LocSeLbstart = 140;
//    static constexpr auto LocSeRight = 91;
//    static constexpr auto LogMsgEvent = 2031;
//    static constexpr auto LogMsgEventCancel = 1319;
//    static constexpr auto Ncut01 = 1352;
//    static constexpr auto NewAnimaGrass = 2002029;
//    static constexpr auto NewSoulstone = 16932;
//    static constexpr auto Ritem0 = 16932;

  public:
    JobRel500() : Sapphire::ScriptAPI::EventScript( 67932 ){}; 
    ~JobRel500() = default; 

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
      case 2:
      {
        Scene00008( player );
        break;
      }
      case 255:
      {
        Scene00011( player );
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
      player.updateQuest( getId(), 2 );
    };

    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
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

    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( JobRel500 );
