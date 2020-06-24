// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False
//parsingResult: -1
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsa404_00746
// Quest Name: Back from the Wood
// Quest ID: 66282
// Start NPC: 1000168
// End NPC: 1006688

using namespace Sapphire;

class GaiUsa404 : public Sapphire::ScriptAPI::EventScript
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
//      Seq1 = 1,
//      Seq2 = 2,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1000168;
//    static constexpr auto Actor1 = 1003785;
//    static constexpr auto Actor2 = 1006688;
//    static constexpr auto CutGaiusa40410 = 96;
//    static constexpr auto LocAction1 = 1002;
//    static constexpr auto LocActor0 = 1003783;
//    static constexpr auto LocSe1 = 42;
//    static constexpr auto LocTalkshape1 = 6;
//    static constexpr auto Territorytype0 = 212;

  public:
    GaiUsa404() : Sapphire::ScriptAPI::EventScript( 66282 ){}; 
    ~GaiUsa404() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
Scene00000( player );
break;
}
case 1:{
Scene00002( player );
break;
}
case 2:{
//no scene is assigned
break;
}
case 255:{
Scene00004( player );
break;
}
default: { player.sendUrgent( "seq {} not defined.", player.getQuestSeq( getId() ) ); break; }
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
player.sendDebug( "questId: {}, calling QuestOffer:Scene00000 +1 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept, FadeOut:Scene00001 ", getId() );

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00003( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 +1 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](2)CutScene:Scene00003 ", getId() );

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00004 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsa404 );
