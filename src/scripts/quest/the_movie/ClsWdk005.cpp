// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ClsWdk005_00168
// Quest Name: A Crisis of Confidence
// Quest ID: 65704
// Start NPC: 1000153
// End NPC: 1000153

using namespace Sapphire;

class ClsWdk005 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestUI8AH
    // GetQuestUI8AL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1000153;
//    static constexpr auto Actor1 = 1000162;
//    static constexpr auto LocAction1 = 990;
//    static constexpr auto LocActor0 = 1004089;
//    static constexpr auto LocEobj1 = 2000993;
//    static constexpr auto LocPosActor1 = 3678101;
//    static constexpr auto LocPosCam1 = 3678103;
//    static constexpr auto LocPosEobj1 = 3841318;
//    static constexpr auto Ritem0 = 5371;
//    static constexpr auto Seq0Actor0 = 0;
//    static constexpr auto Seq1Actor1 = 1;
//    static constexpr auto Seq2Actor0 = 2;
//    static constexpr auto Seq2Actor0Npctradeno = 99;
//    static constexpr auto Seq2Actor0Npctradeok = 100;

  public:
    ClsWdk005() : Sapphire::ScriptAPI::EventScript( 65704 ){}; 
    ~ClsWdk005() = default; 

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
      case 255:
      {
        Scene00002( player );
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
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00100( player );
    };

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00099( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 99, NONE, callback );
  }

  void Scene00100( Entity::Player& player )
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

    player.playScene( getId(), 100, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( ClsWdk005 );
