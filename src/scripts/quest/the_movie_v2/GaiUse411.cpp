// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: True, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse411_00079
// Quest Name: Chasing Ivy
// Quest ID: 65615
// Start NPC: 1010010
// End NPC: 1010017

using namespace Sapphire;

class GaiUse411 : public Sapphire::ScriptAPI::EventScript
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
//      Seq4 = 4,
//      Seq5 = 5,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineEventBaseStandPose2 = 1053;
//    static constexpr auto ActionTimelineEventSaluteCry = 1045;
//    static constexpr auto Actor0 = 1010010;
//    static constexpr auto Actor1 = 1010011;
//    static constexpr auto Actor2 = 1010017;
//    static constexpr auto Actor3 = 1010019;
//    static constexpr auto Actor4 = 1010018;
//    static constexpr auto Actor5 = 1010012;
//    static constexpr auto Actor6 = 1010013;
//    static constexpr auto Actor7 = 1010014;
//    static constexpr auto Actor8 = 1010015;
//    static constexpr auto Actor9 = 1010016;
//    static constexpr auto BgmNothing = 1;
//    static constexpr auto CutSceneN01 = 618;
//    static constexpr auto LevelIdNpc01 = 5098064;
//    static constexpr auto LocActor0 = 1009972;
//    static constexpr auto LocBgm01 = 85;

  public:
    GaiUse411() : Sapphire::ScriptAPI::EventScript( 65615 ){}; 
    ~GaiUse411() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1010010 ) { Scene00000( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1010011 ) { Scene00003( player ); }
break;
}
case 1:{
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1010017 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00004( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1010019 ) { Scene00006( player ); }
break;
}
case 2:{
Scene00007( player );
break;
}
case 3:{
//ACTOR5, UI8AL, 1, -2, False
if( actor == 1010012 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00008( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1010018 ) { Scene00010( player ); }
break;
}
case 4:{
//ACTOR4, UI8AL, 1, -2, False
if( actor == 1010018 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00011( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1010012 ) { Scene00013( player ); }
break;
}
case 5:{
//ACTOR6, UI8BH, 2, -2, False
if( actor == 1010013 && player.getQuestUI8BH( getId() ) != 2 ) { Scene00014( player ); }
//ACTOR7, UI8BH, 2, -2, False
if( actor == 1010014 && player.getQuestUI8BH( getId() ) != 2 ) { Scene00016( player ); }
//ACTOR8, UI8AL, 2, -2, False
if( actor == 1010015 && player.getQuestUI8AL( getId() ) != 2 ) { Scene00018( player ); }
//ACTOR9, UI8AL, 2, -2, False
if( actor == 1010016 && player.getQuestUI8AL( getId() ) != 2 ) { Scene00020( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1010012 ) { Scene00021( player ); }
break;
}
case 255:{
//ACTOR2, null, 0, -2, False
if( actor == 1010017 ) { Scene00020( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1010012 ) { Scene00021( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1010013 ) { Scene00022( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1010014 ) { Scene00023( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1010015 ) { Scene00024( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1010016 ) { Scene00025( player ); }
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
player.sendDebug( "questId: {}, calling QuestOffer:Scene00000 +2 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
Scene00002( player );
    };
player.sendDebug( "questId: {}, calling [sub:Intro](0)CutScene:Scene00001 ACTOR0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)QuestAccept:Scene00002 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR1", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00005( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 +1 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](4)Talk:Scene00005 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00006 ACTOR3", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00009( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 +1 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 4 );
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](8)Talk:Scene00009 ACTOR5:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ACTOR4", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00012( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 +1 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 5 );
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](11)Talk:Scene00012 ACTOR4:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 ACTOR5", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00015( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 +1 ", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 2 ){
if( player.getQuestUI8AL( getId() ) == 2 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](14)Talk:Scene00015 ACTOR6:UI8BH=-2, 2", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00017( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 +1 ", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 2 ){
if( player.getQuestUI8AL( getId() ) == 2 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](16)Talk:Scene00017 ACTOR7:UI8BH=-2, 2", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00019( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 +1 ", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 2 ){
if( player.getQuestUI8AL( getId() ) == 2 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](18)Talk:Scene00019 ACTOR8:UI8AL=-2, 2", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete, FadeOut:Scene00020 ACTOR2", getId() );

    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00021 ACTOR5", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00022 ACTOR6", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00023 ACTOR7", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00024 ACTOR8", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00025 ACTOR9", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse411 );
