// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: True, A2: False, A3: False, S: True, R: False, DM: False, L: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ManSea007_00544
// Quest Name: Feint and Strike
// Quest ID: 66080
// Start NPC: 1000972
// End NPC: 1003282

using namespace Sapphire;

class ManSea007 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AL
    // GetQuestUI8BH

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
//    static constexpr auto Actor0 = 1000972;
//    static constexpr auto Actor1 = 1003282;
//    static constexpr auto Actor2 = 1003283;
//    static constexpr auto Actor3 = 1003284;
//    static constexpr auto Actor4 = 1003285;
//    static constexpr auto Actor5 = 1003286;
//    static constexpr auto CutEvent0 = 207;
//    static constexpr auto CutEvent1 = 211;
//    static constexpr auto CutEvent2 = 136;
//    static constexpr auto CutScene03 = 210;
//    static constexpr auto Eobject0 = 2001739;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000519;
//    static constexpr auto LocActor0 = 1005031;
//    static constexpr auto LocFace0 = 604;
//    static constexpr auto LocFace1 = 617;
//    static constexpr auto Questbattle0 = 36;
//    static constexpr auto Territorytype0 = 280;
//    static constexpr auto Territorytype1 = 138;

  public:
    ManSea007() : Sapphire::ScriptAPI::EventScript( 66080 ){}; 
    ~ManSea007() = default; 

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
player.sendUrgent( "This scene contains quest battle." );
player.sendUrgent( "If stuck in black loading screen, enter and exit \"/gpose\" to get rid of it." );
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1003283 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00004( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1003284 ) { Scene00005( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1003285 ) { Scene00007( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1003286 ) { Scene00008( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2001739 ) { Scene00009( player ); }
break;
}
case 3:{
Scene00011( player );
break;
}
case 255:{
Scene00012( player );
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
player.sendDebug( "questId: {}, calling Talk, QuestOffer:Scene00000 +1 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 1 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)QuestAccept, CutScene:Scene00001 ", getId() );

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00003( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00002 +1 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](2)Talk, FadeOut:Scene00003 ", getId() );

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
if( result.param2 == 1 ){
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
Scene00011( player );
}
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestBattle, YesNo:Scene00004 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00006( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 +1 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](5)Talk:Scene00006 ACTOR3", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR4", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00008 ACTOR5", getId() );


  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00010( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00009 +1 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](9)CutScene:Scene00010 EOBJECT0", getId() );

    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling CutScene, QuestReward, QuestComplete, FadeOut:Scene00012 ", getId() );

    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( ManSea007 );
