// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: StmBdi101_03003
// Quest Name: Dramatis Personae
// Quest ID: 68539
// Start NPC: 1018994
// End NPC: 1024142

using namespace Sapphire;

class StmBdi101 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1018994;
//    static constexpr auto Actor1 = 1024140;
//    static constexpr auto Actor10 = 1024144;
//    static constexpr auto Actor2 = 1024141;
//    static constexpr auto Actor3 = 1024155;
//    static constexpr auto Actor4 = 1024154;
//    static constexpr auto Actor5 = 1024157;
//    static constexpr auto Actor6 = 1024160;
//    static constexpr auto Actor7 = 1024161;
//    static constexpr auto Actor8 = 1024142;
//    static constexpr auto Actor9 = 1024143;
//    static constexpr auto AristocratGreeting = 5544;
//    static constexpr auto BindAlma01 = 7075315;
//    static constexpr auto BindAlma02 = 7075596;
//    static constexpr auto BindCa = 7078696;
//    static constexpr auto Eobject0 = 2008621;
//    static constexpr auto EventPictrueRtiQuest101001 = 563;
//    static constexpr auto LocAlma = 1023975;
//    static constexpr auto LocBgmBackgroundStory = 514;
//    static constexpr auto LocBgmHeroTheme = 512;
//    static constexpr auto LocBgmPlayerCreation = 511;
//    static constexpr auto LocBgmToho = 465;
//    static constexpr auto LocBindRina02 = 7078252;
//    static constexpr auto LocCid = 1011900;
//    static constexpr auto LocCry = 956;
//    static constexpr auto LocFemale001 = 1024208;
//    static constexpr auto LocFemale002 = 1024209;
//    static constexpr auto LocFemale003 = 1024210;
//    static constexpr auto LocHand = 5533;
//    static constexpr auto LocJakuemi = 6215;
//    static constexpr auto LocKanmu = 6216;
//    static constexpr auto LocKomaru = 625;
//    static constexpr auto LocKurogai = 1024207;
//    static constexpr auto LocMale001 = 1024211;
//    static constexpr auto LocMale002 = 1024212;
//    static constexpr auto LocMoveALina = 7081509;
//    static constexpr auto LocMoveBLina = 7081507;
//    static constexpr auto LocObie3 = 4215;
//    static constexpr auto LocPosLinaOodougu = 7155656;
//    static constexpr auto LocPosNigiyakashi = 7083002;
//    static constexpr auto LocRightTrun = 4256;
//    static constexpr auto LocRina = 1023978;
//    static constexpr auto NcutStmbdi00010 = 1637;
//    static constexpr auto NcutStmbdi00020 = 1638;
//    static constexpr auto Poprange0 = 7077602;
//    static constexpr auto Poprange1 = 7076909;
//    static constexpr auto Poprange2 = 7078276;
//    static constexpr auto QstClshrv502 = 67584;
//    static constexpr auto Territorytype0 = 736;

  public:
    StmBdi101() : Sapphire::ScriptAPI::EventScript( 68539 ){}; 
    ~StmBdi101() = default; 

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
        Scene00014( player );
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

    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
      Scene00010( player );
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

    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };

    player.playScene( getId(), 12, NONE, callback );
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
      if( result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
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
    };

    player.playScene( getId(), 16, NONE, callback );
  }

};

EXPOSE_SCRIPT( StmBdi101 );
