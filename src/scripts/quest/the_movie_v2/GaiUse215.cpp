// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: True, S: True, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse215_01359
// Quest Name: The Gift of Eternity
// Quest ID: 66895
// Start NPC: 1006614
// End NPC: 1008803

using namespace Sapphire;

class GaiUse215 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineEventBaseAttentionStand = 1013;
//    static constexpr auto Actor0 = 1006614;
//    static constexpr auto Actor1 = 1008698;
//    static constexpr auto Actor2 = 1008699;
//    static constexpr auto Actor3 = 1008688;
//    static constexpr auto Actor4 = 1008689;
//    static constexpr auto Actor5 = 1008928;
//    static constexpr auto Actor6 = 1008706;
//    static constexpr auto Actor7 = 1008803;
//    static constexpr auto BgmNothing = 1;
//    static constexpr auto CutSceneN01 = 467;
//    static constexpr auto CutSceneN02 = 468;
//    static constexpr auto Enemy0 = 4628675;
//    static constexpr auto Enemy1 = 4628676;
//    static constexpr auto Enemy10 = 4628687;
//    static constexpr auto Enemy11 = 4628688;
//    static constexpr auto Enemy12 = 4628692;
//    static constexpr auto Enemy13 = 4628693;
//    static constexpr auto Enemy14 = 4628694;
//    static constexpr auto Enemy2 = 4628678;
//    static constexpr auto Enemy3 = 4628679;
//    static constexpr auto Enemy4 = 4628680;
//    static constexpr auto Enemy5 = 4628681;
//    static constexpr auto Enemy6 = 4628682;
//    static constexpr auto Enemy7 = 4628683;
//    static constexpr auto Enemy8 = 4628684;
//    static constexpr auto Enemy9 = 4628685;
//    static constexpr auto Eobject0 = 2003591;
//    static constexpr auto Eobject1 = 2003592;
//    static constexpr auto Eobject2 = 2003593;
//    static constexpr auto Eobject3 = 2003594;
//    static constexpr auto Eobject4 = 2003595;
//    static constexpr auto Eventrange0 = 4628666;
//    static constexpr auto Eventrange1 = 4628667;
//    static constexpr auto Eventrange2 = 4628668;
//    static constexpr auto Eventrange3 = 4628669;
//    static constexpr auto Eventrange4 = 4628672;
//    static constexpr auto EventActionRescueUpperMiddle = 39;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto LocActor0 = 1008183;
//    static constexpr auto LocActor1 = 1008175;
//    static constexpr auto LocActor2 = 4628705;
//    static constexpr auto LocActor3 = 4628706;
//    static constexpr auto LocActor4 = 4628707;
//    static constexpr auto LocActor5 = 4334136;
//    static constexpr auto LocFace0 = 617;
//    static constexpr auto LocFace1 = 605;
//    static constexpr auto LocFace2 = 612;
//    static constexpr auto LocPosActor1 = 4675591;
//    static constexpr auto Poprange0 = 4635439;

  public:
    GaiUse215() : Sapphire::ScriptAPI::EventScript( 66895 ){}; 
    ~GaiUse215() = default; 

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
//if( actorId == 4628675 && player.getQuestUI8BH( getId() ) != 2 ) { Scene?????( player ); }
//if( actorId == 4628676 && player.getQuestUI8BH( getId() ) != 2 ) { Scene?????( player ); }
//if( actorId == 4628678 && player.getQuestUI8AL( getId() ) != 2 ) { Scene?????( player ); }
//if( actorId == 4628679 && player.getQuestUI8AL( getId() ) != 2 ) { Scene?????( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2003591 ) { Scene00002( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2003592 ) { Scene00004( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1008698 ) { Scene00006( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1008699 ) { Scene00008( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008688 ) { Scene00010( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008689 ) { Scene00011( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1008928 ) { Scene00013( player ); }
break;
}
case 2:{
//EOBJECT2, null, 0, -2, False
if( actor == 2003593 ) { Scene00015( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2003594 ) { Scene00017( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1008698 ) { Scene00019( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1008699 ) { Scene00021( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008688 ) { Scene00023( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008689 ) { Scene00025( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1008928 ) { Scene00027( player ); }
break;
}
case 3:{
//EOBJECT4, null, 0, -2, False
if( actor == 2003595 ) { Scene00028( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1008698 ) { Scene00030( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1008699 ) { Scene00032( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008688 ) { Scene00034( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008689 ) { Scene00036( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1008928 ) { Scene00038( player ); }
break;
}
case 4:{
//ACTOR6, UI8AL, 1, -2, False
if( actor == 1008706 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00040( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1008698 ) { Scene00042( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1008699 ) { Scene00044( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008688 ) { Scene00045( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008689 ) { Scene00046( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1008928 ) { Scene00048( player ); }
break;
}
case 255:{
Scene00050( player );
break;
}
default: { player.sendUrgent( "seq {} not defined.", player.getQuestSeq( getId() ) ); break; }
}
  }

  void onBNpcKill( uint32_t npcId, Entity::Player& player ) override
  {
//    switch( npcId )
//    {
//      case Enemy0: { break; }
//      case Enemy1: { break; }
//      case Enemy2: { break; }
//      case Enemy3: { break; }
//      case Enemy4: { break; }
//      case Enemy5: { break; }
//      case Enemy6: { break; }
//      case Enemy7: { break; }
//      case Enemy8: { break; }
//      case Enemy9: { break; }
//      case Enemy10: { break; }
//      case Enemy11: { break; }
//      case Enemy12: { break; }
//      case Enemy13: { break; }
//      case Enemy14: { break; }
//    }
onTalk( getId(), player, npcId );
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
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00002 +1 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](2)Empty:Scene00003 EOBJECT0", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00005( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00004 +1 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](4)Message:Scene00005 EOBJECT1", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00007( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00006 +1 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {


//Target: ACTOR1
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](6)Empty:Scene00007 ACTOR1", getId() );


  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00009( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00008 +1 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR2
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](8)Empty:Scene00009 ACTOR2", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//no valid quest var detected
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ACTOR3", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00012( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00011 +1 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR4
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](11)Empty:Scene00012 ACTOR4", getId() );


  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00014( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00013 +1 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {


//Target: ACTOR5
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](13)Empty:Scene00014 ACTOR5", getId() );


  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00015 +1 ", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](15)Empty:Scene00016 EOBJECT2", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00018( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00017 +1 ", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
player.updateQuest( getId(), 3 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](17)Empty:Scene00018 EOBJECT3", getId() );


  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00020( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00019 +1 ", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](19)Message:Scene00020 ACTOR1", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00022( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00021 +1 ", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {


//Target: ACTOR2
//no valid quest var detected
player.updateQuest( getId(), 3 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](21)Empty:Scene00022 ACTOR2", getId() );


  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00024( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00023 +1 ", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {


//Target: ACTOR3
//no valid quest var detected
player.updateQuest( getId(), 3 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](23)Empty:Scene00024 ACTOR3", getId() );


  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00026( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00025 +1 ", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {


//Target: ACTOR4
//no valid quest var detected
player.updateQuest( getId(), 3 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](25)Empty:Scene00026 ACTOR4", getId() );


  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00027 ACTOR5", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00029( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00028 +1 ", getId() );

    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {


//Target: EOBJECT4
//no valid quest var detected
player.updateQuest( getId(), 4 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](28)Empty:Scene00029 EOBJECT4", getId() );


  }

  void Scene00030( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00031( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00030 +1 ", getId() );

    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {


//Target: ACTOR1
//no valid quest var detected
player.updateQuest( getId(), 4 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](30)Empty:Scene00031 ACTOR1", getId() );


  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00032 +1 ", getId() );

    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](32)Empty:Scene00033 ACTOR2", getId() );

    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00035( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00034 +1 ", getId() );

    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {


//Target: ACTOR3
//no valid quest var detected
player.updateQuest( getId(), 4 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](34)Empty:Scene00035 ACTOR3", getId() );


  }

  void Scene00036( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00037( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00036 +1 ", getId() );

    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//no valid quest var detected
player.updateQuest( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](36)Talk:Scene00037 ACTOR4", getId() );

    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00039( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00038 +1 ", getId() );

    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {


//Target: ACTOR5
//no valid quest var detected
player.updateQuest( getId(), 4 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](38)Empty:Scene00039 ACTOR5", getId() );


  }

  void Scene00040( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00041( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00040 +1 ", getId() );

    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {


//Target: ACTOR6
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](40)Empty:Scene00041 ACTOR6:UI8AL=-2, 1", getId() );


  }

  void Scene00042( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00043( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00042 +1 ", getId() );

    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](42)Talk:Scene00043 ACTOR1", getId() );

    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling CutScene:Scene00044 ACTOR2", getId() );

    player.playScene( getId(), 44, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00045 ACTOR3", getId() );

    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00047( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00046 +1 ", getId() );

    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](46)Empty:Scene00047 ACTOR4", getId() );


  }

  void Scene00048( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00049( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00048 +1 ", getId() );

    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](48)Empty:Scene00049 ACTOR5", getId() );


  }

  void Scene00050( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00050 ", getId() );

    player.playScene( getId(), 50, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse215 );
