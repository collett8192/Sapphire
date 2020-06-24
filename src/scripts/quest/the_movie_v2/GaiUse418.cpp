// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse418_00088
// Quest Name: The Reason Roaille
// Quest ID: 65624
// Start NPC: 1008969
// End NPC: 1010063

using namespace Sapphire;

class GaiUse418 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineEventSaluteCry = 1045;
//    static constexpr auto Actor0 = 1008969;
//    static constexpr auto Actor1 = 1010045;
//    static constexpr auto Actor2 = 1010702;
//    static constexpr auto Actor3 = 1010533;
//    static constexpr auto Actor4 = 1010046;
//    static constexpr auto Actor5 = 1010060;
//    static constexpr auto Actor6 = 1010061;
//    static constexpr auto Actor7 = 1010062;
//    static constexpr auto Actor8 = 1010063;
//    static constexpr auto Actor9 = 1010534;
//    static constexpr auto CutSceneN01 = 626;
//    static constexpr auto Eobject0 = 2004662;
//    static constexpr auto LocActor0 = 5375032;
//    static constexpr auto Questbattle0 = 101;
//    static constexpr auto Territorytype0 = 410;

  public:
    GaiUse418() : Sapphire::ScriptAPI::EventScript( 65624 ){}; 
    ~GaiUse418() = default; 

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
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1010045 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1008969 ) { Scene00003( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1010702 ) { Scene00004( player ); }
break;
}
case 2:{
Scene00005( player );
break;
}
case 3:{
player.sendUrgent( "This scene contains quest battle." );
player.sendUrgent( "If stuck in black loading screen, enter and exit \"/gpose\" to get rid of it." );
//ACTOR4, UI8AL, 1, -2, False
if( actor == 1010046 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00006( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2004662 ) { Scene00007( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1010060 ) { Scene00008( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1010061 ) { Scene00009( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1010062 ) { Scene00010( player ); }
break;
}
case 255:{
//ACTOR8, null, 0, -2, False
if( actor == 1010063 ) { Scene00011( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1010534 ) { Scene00013( player ); }
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
//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR0", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00004 ACTOR2", getId() );


  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
if( result.param2 == 1 ){
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
    };
player.sendDebug( "questId: {}, calling QuestBattle, YesNo:Scene00006 ACTOR4:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00007 EOBJECT0", getId() );


  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR5", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR6", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR7", getId() );


  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 )
Scene00012( player );
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward:Scene00011 +1 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
    };
player.sendDebug( "questId: {}, calling [sub:Complete](11)CutScene, QuestComplete:Scene00012 ACTOR8", getId() );

    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 ACTOR9", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse418 );
