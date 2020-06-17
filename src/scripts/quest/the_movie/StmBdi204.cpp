// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: StmBdi204_03092
// Quest Name: Annihilation
// Quest ID: 68628
// Start NPC: 1025741
// End NPC: 1024149

using namespace Sapphire;

class StmBdi204 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1025741;
//    static constexpr auto Actor1 = 5010000;
//    static constexpr auto Actor2 = 1024149;
//    static constexpr auto EventActionKashige = 958;
//    static constexpr auto EventActionManzoku = 1023;
//    static constexpr auto EventActionZannen = 1024;
//    static constexpr auto EventTrouble = 944;
//    static constexpr auto Instancedungeon0 = 30068;
//    static constexpr auto LocBgmBackgroundStory = 514;
//    static constexpr auto LocBgmChapel = 554;
//    static constexpr auto LocBgmHeroTheme = 512;
//    static constexpr auto LocBgmPlayerCreation = 511;
//    static constexpr auto LocBindAlma = 7460234;
//    static constexpr auto LocBindBwagi = 7460241;
//    static constexpr auto LocBindHurdy = 7460231;
//    static constexpr auto LocBindMikoto = 7460238;
//    static constexpr auto LocBindMontblance = 7460232;
//    static constexpr auto LocBindRamza = 7460233;
//    static constexpr auto LocBindRina = 7460237;
//    static constexpr auto LocBindRinok = 7460240;
//    static constexpr auto LocDance = 965;
//    static constexpr auto LocHand = 5533;
//    static constexpr auto LocJakuemi = 6215;
//    static constexpr auto LocKabau = 5563;
//    static constexpr auto LocKiri = 624;
//    static constexpr auto LocKomaru = 625;
//    static constexpr auto LocLeftTrun = 4257;
//    static constexpr auto LocMedlitate = 6227;
//    static constexpr auto LocObie3 = 4215;
//    static constexpr auto LocRightTrun = 4256;
//    static constexpr auto NcutStmbdi01070 = 1770;
//    static constexpr auto NcutStmbdi01080 = 1771;
//    static constexpr auto Poprange0 = 7393808;
//    static constexpr auto Poprange1 = 7080627;
//    static constexpr auto Territorytype0 = 735;
//    static constexpr auto UnlockImageDungeon = 605;

  public:
    StmBdi204() : Sapphire::ScriptAPI::EventScript( 68628 ){}; 
    ~StmBdi204() = default; 

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

    player.playScene( getId(), 1, NONE, callback );
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

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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

    player.playScene( getId(), 4, NONE, callback );
  }

};

EXPOSE_SCRIPT( StmBdi204 );
