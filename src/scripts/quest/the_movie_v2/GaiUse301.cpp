// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse301_01442
// Quest Name: The Great Divide
// Quest ID: 66978
// Start NPC: 1008579
// End NPC: 1008623

using namespace Sapphire;

class GaiUse301 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1008579;
//    static constexpr auto Actor1 = 1009239;
//    static constexpr auto Actor2 = 1009240;
//    static constexpr auto Actor3 = 1009241;
//    static constexpr auto Actor4 = 1008623;
//    static constexpr auto CutSceneN01 = 484;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto LevelIdNpc01 = 4841541;
//    static constexpr auto LevelIdNpc02 = 4841542;
//    static constexpr auto LocAction0 = 613;
//    static constexpr auto LocAction1 = 615;
//    static constexpr auto LocAction2 = 620;
//    static constexpr auto LocAction3 = 605;
//    static constexpr auto LocAction4 = 617;
//    static constexpr auto LocActor0 = 1008266;
//    static constexpr auto LocActor1 = 1009240;
//    static constexpr auto LocActor10 = 4505914;
//    static constexpr auto LocActor11 = 4550383;
//    static constexpr auto LocActor2 = 1009241;
//    static constexpr auto LocActor3 = 1008175;
//    static constexpr auto LocActor4 = 1008182;
//    static constexpr auto LocBgm0 = 97;
//    static constexpr auto LocBgm1 = 78;
//    static constexpr auto LocPosActor0 = 4881124;
//    static constexpr auto LocPosActor1 = 4892117;
//    static constexpr auto LocSe0 = 68;
//    static constexpr auto LocSe1 = 39;

  public:
    GaiUse301() : Sapphire::ScriptAPI::EventScript( 66978 ){}; 
    ~GaiUse301() = default; 

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
if( actor == 1009239 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1009240 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009241 ) { Scene00004( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1008579 ) { Scene00005( player ); }
break;
}
case 255:{
//ACTOR4, null, 0, -2, False
if( actor == 1008623 ) { Scene00007( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1009239 ) { Scene00008( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1009240 ) { Scene00009( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009241 ) { Scene00010( player ); }
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
//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00002 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00003 ACTOR2", getId() );


  }

  void Scene00004( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00004 ACTOR3", getId() );


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
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](5)CutScene:Scene00006 ACTOR0", getId() );

    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling QuestReward, QuestComplete, FadeOut:Scene00007 ACTOR4", getId() );

    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR1", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR2", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR3", getId() );


  }

};

EXPOSE_SCRIPT( GaiUse301 );
