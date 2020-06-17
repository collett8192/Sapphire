// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: LucKlz000_03655
// Quest Name: The Crystalline Mean
// Quest ID: 69191
// Start NPC: 1027232
// End NPC: 1027232

using namespace Sapphire;

class LucKlz000 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestUI8AL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1027232;
//    static constexpr auto LocEnpc01 = 1028460;
//    static constexpr auto LocEnpc02 = 1028509;
//    static constexpr auto LocEnpc03 = 1028441;
//    static constexpr auto LocEnpc04 = 1028445;
//    static constexpr auto LocEnpc05 = 1029652;
//    static constexpr auto LocEnpc06 = 1028461;
//    static constexpr auto LocPubEnpc01 = 1027233;
//    static constexpr auto LocPubEnpc02 = 1028326;
//    static constexpr auto LocPubEnpc03 = 1027235;
//    static constexpr auto LocPubEnpc04 = 1027236;
//    static constexpr auto LocPubEnpc05 = 1027237;
//    static constexpr auto LocPubEnpc06 = 1028323;
//    static constexpr auto LocQuestCheck01 = 67631;

  public:
    LucKlz000() : Sapphire::ScriptAPI::EventScript( 69191 ){}; 
    ~LucKlz000() = default; 

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
        Scene00001( player );
    };

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
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

    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( LucKlz000 );
