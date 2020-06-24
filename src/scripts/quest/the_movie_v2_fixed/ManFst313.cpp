// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False
//parsingResult: -1
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ManFst313_00517
// Quest Name: All Good Things
// Quest ID: 66053
// Start NPC: 1006343
// End NPC: 1006355

using namespace Sapphire;

class ManFst313 : public Sapphire::ScriptAPI::EventScript
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
//      Seq3 = 3,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006343;
//    static constexpr auto Actor1 = 1003281;
//    static constexpr auto Actor2 = 1007686;
//    static constexpr auto Actor3 = 1007687;
//    static constexpr auto Actor4 = 1007688;
//    static constexpr auto Actor5 = 1007689;
//    static constexpr auto Actor6 = 1007467;
//    static constexpr auto Actor7 = 1006355;
//    static constexpr auto CutManfst31310 = 246;
//    static constexpr auto CutManfst31320 = 98;
//    static constexpr auto CutManfst31330 = 247;
//    static constexpr auto CutManfst31340 = 248;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto LocAction1 = 1002;
//    static constexpr auto LocActor0 = 1003783;
//    static constexpr auto LocActor1 = 1002387;
//    static constexpr auto LocActor2 = 1002388;
//    static constexpr auto LocActor3 = 1003247;
//    static constexpr auto LocActor4 = 1002389;
//    static constexpr auto LocFace0 = 604;
//    static constexpr auto LocFace1 = 605;
//    static constexpr auto LocPosActor1 = 4333952;
//    static constexpr auto LocPosActor2 = 4333953;
//    static constexpr auto LocPosActor3 = 4333954;
//    static constexpr auto LocPosActor4 = 4333955;
//    static constexpr auto LocSe1 = 42;
//    static constexpr auto LocTalkshape1 = 6;
//    static constexpr auto Territorytype0 = 212;

  public:
    ManFst313() : Sapphire::ScriptAPI::EventScript( 66053 ){}; 
    ~ManFst313() = default; 

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
//BASE_ID_TERRITORY_TYPE, null, 0, -2, False
//if( actor == BASE_ID_TERRITORY_TYPE ) { Scene00003( player ); }
//ACTOR2, null, 0, -2, False
if( actorId == 4299300707 ) { Scene00004( player ); }
//ACTOR3, null, 0, -2, False
if( actorId == 4299300708 ) { Scene00005( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007688 ) { Scene00006( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1007689 ) { Scene00007( player ); }
break;
}
case 3:{
  Scene00008( player );
break;
}
case 255:{
Scene00009( player );
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
player.sendUrgent("after entering the walking sand, type \"//gm quest sequence 66053 3\" to skip the territory trigger");
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00002 ", getId() );
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: BASE_ID_TERRITORY_TYPE
//no valid quest var detected
//player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling FadeOut:Scene00003 BASE_ID_TERRITORY_TYPE", getId() );

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
//player.updateQuest( getId(), 255 );
      player.sendUrgent("after entering the walking sand, type \"//gm quest sequence 66053 3\" to skip the territory trigger");
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR2", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//no valid quest var detected
//player.updateQuest( getId(), 255 );
      player.sendUrgent("after entering the walking sand, type \"//gm quest sequence 66053 3\" to skip the territory trigger");
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ACTOR3", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {


//Target: ACTOR4
//no valid quest var detected
//player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00006 ACTOR4", getId() );


  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//{ Scene00008( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00007 +1 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](7)CutScene:Scene00008 ACTOR5", getId() );

    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 )
Scene00010( player );
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward:Scene00009 +1 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
    };
player.sendDebug( "questId: {}, calling [sub:Complete](9)CutScene, QuestComplete:Scene00010 ", getId() );

    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( ManFst313 );
