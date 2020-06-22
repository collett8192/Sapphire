// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2

#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ManFst407_00521
// Quest Name: Escape from Castrum Centri
// Quest ID: 66057
// Start NPC: 1006555
// End NPC: 1006573

using namespace Sapphire;

class ManFst407 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL

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
//      Seq6 = 6,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006555;
//    static constexpr auto Actor1 = 1006530;
//    static constexpr auto Actor10 = 1006569;
//    static constexpr auto Actor11 = 1007611;
//    static constexpr auto Actor12 = 1006562;
//    static constexpr auto Actor13 = 1007694;
//    static constexpr auto Actor14 = 1007696;
//    static constexpr auto Actor15 = 1006573;
//    static constexpr auto Actor16 = 1004433;
//    static constexpr auto Actor2 = 1007538;
//    static constexpr auto Actor3 = 1007539;
//    static constexpr auto Actor4 = 1007670;
//    static constexpr auto Actor5 = 1007537;
//    static constexpr auto Actor6 = 1006531;
//    static constexpr auto Actor7 = 1006567;
//    static constexpr auto Actor8 = 1007614;
//    static constexpr auto Actor9 = 1006568;
//    static constexpr auto CutScene01 = 293;
//    static constexpr auto CutScene02 = 113;
//    static constexpr auto CutSceneAfter00 = 456;
//    static constexpr auto CutSceneAfter01 = 287;
//    static constexpr auto CutSceneAfter02 = 114;
//    static constexpr auto CutSceneAfter03 = 288;
//    static constexpr auto CutSceneAfter04 = 260;
//    static constexpr auto Eobject0 = 2002376;
//    static constexpr auto EventActionTouchMiddle = 46;
//    static constexpr auto Item0 = 2000773;
//    static constexpr auto LocAction1 = 990;
//    static constexpr auto LocActor0 = 1007697;
//    static constexpr auto LocActor1 = 1007006;
//    static constexpr auto LocActor2 = 1007023;
//    static constexpr auto LocActor8 = 1006563;
//    static constexpr auto LocActor9 = 1007614;
//    static constexpr auto LocFace1 = 617;
//    static constexpr auto LocFace2 = 620;
//    static constexpr auto LocPosActor0 = 4332128;
//    static constexpr auto LocPosActor1 = 4332129;
//    static constexpr auto LocSe1 = 44;
//    static constexpr auto LocSe2 = 45;
//    static constexpr auto Poprange0 = 4321644;
//    static constexpr auto Poprange1 = 4304063;
//    static constexpr auto Poprange2 = 4305281;
//    static constexpr auto Poprange3 = 4103351;
//    static constexpr auto Questbattle0 = 65;
//    static constexpr auto Ritem0 = 6223;
//    static constexpr auto Ritem1 = 6224;
//    static constexpr auto Territorytype0 = 156;
//    static constexpr auto Territorytype1 = 335;
//    static constexpr auto Territorytype2 = 305;
//    static constexpr auto Territorytype3 = 130;

  public:
    ManFst407() : Sapphire::ScriptAPI::EventScript( 66057 ){}; 
    ~ManFst407() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
//if( actor == 1006555 && player.getQuestUI8AL( getId() ) != 1 ) { Scene?????( player ); }
//if( actor == 1006530 ) { Scene?????( player ); }
Scene00000( player );
break;
}
case 1:{
//ACTOR2, null, 0, -2, False
if( actor == 1007538 ) { Scene00002( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1007539 ) { Scene00003( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007670 ) { Scene00004( player ); }
//ACTOR5, UI8AL, 1, -2, False
if( actor == 1007537 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00005( player ); }
//ACTOR6, null, 0, -2, True
if( actor == 1006531 ) { Scene00006( player ); }
break;
}
case 2:{
//ACTOR7, UI8BL, 1, -2, False
if( actor == 1006567 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00007( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1007537 ) { Scene00009( player ); }
//ACTOR6, null, 0, -2, True
if( actor == 1006531 ) { Scene00010( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1007614 ) { Scene00011( player ); }
//ACTOR9, UI8AL, 1, -2, False
if( actor == 1006568 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00012( player ); }
//ACTOR10, UI8BH, 1, -2, False
if( actor == 1006569 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00013( player ); }
break;
}
case 3:{
//ACTOR11, UI8AL, 1, -2, False
if( actor == 1007611 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00014( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1007537 ) { Scene00015( player ); }
//ACTOR6, null, 0, -2, True
if( actor == 1006531 ) { Scene00016( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1007614 ) { Scene00017( player ); }
break;
}
case 4:{
//ACTOR12, UI8AL, 1, -2, False
if( actor == 1006562 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00018( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1007537 ) { Scene00021( player ); }
//ACTOR6, null, 0, -2, True
if( actor == 1006531 ) { Scene00022( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1007614 ) { Scene00023( player ); }
break;
}
case 5:{
//EOBJECT0, UI8AL, 1, -2, False
if( actor == 2002376 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00024( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1007537 ) { Scene00025( player ); }
//ACTOR6, null, 0, -2, True
if( actor == 1006531 ) { Scene00026( player ); }
//ACTOR13, null, 0, -2, False
if( actor == 1007694 ) { Scene00027( player ); }
//ACTOR14, null, 0, -2, False
if( actor == 1007696 ) { Scene00028( player ); }
break;
}
case 6:{
Scene00029( player );
break;
}
case 255:{
//ACTOR15, null, 0, -2, False
if( actor == 1006573 ) { Scene00041( player ); }
//ACTOR16, null, 0, -2, False
if( actor == 1004433 ) { Scene00042( player ); }
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


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00002 ACTOR2", getId() );


  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00003 ACTOR3", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00004 ACTOR4", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: ACTOR5
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00005 ACTOR5:UI8AL=-2, 1", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00006 ACTOR6", getId() );


  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00008( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00007 +1 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 1 );
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](7)CutScene:Scene00008 ACTOR7:UI8BL=-2, 1", getId() );

    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR5", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ACTOR6", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 ACTOR8", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 1 );
}
}
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ACTOR9:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 1 );
}
}
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 ACTOR10:UI8BH=-2, 1", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR11
if( result.param2 == 1 ){
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
}
}
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00014 ACTOR11:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 ACTOR5", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00016 ACTOR6", getId() );


  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ACTOR8", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00019( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 +2 ", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR12
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 5 );
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](18)Talk:Scene00019 ACTOR12:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](18)Talk:Scene00020 ", getId() );

    player.playScene( getId(), 20, NONE, callback );
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
//Target: ACTOR8
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00023 ACTOR8", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 6 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00024 EOBJECT0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00025 ACTOR5", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00026 ACTOR6", getId() );

    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR13
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00027 ACTOR13", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {


//Target: ACTOR14
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00028 ACTOR14", getId() );


  }

  void Scene00029( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00030( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00029 +1 ", getId() );

    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](29)Talk, FadeOut:Scene00030 ", getId() );

    player.playScene( getId(), 30, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00031 ", getId() );

    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00032 ", getId() );

    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00033 ", getId() );


  }

  void Scene00034( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00034 ", getId() );

    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling QuestBattle, YesNo:Scene00035 ", getId() );

    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00036 ", getId() );

    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00037 ", getId() );

    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00038 ", getId() );


  }

  void Scene00039( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00040( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00039 +1 ", getId() );

    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](39)CutScene:Scene00040 ", getId() );

    player.playScene( getId(), 40, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR15
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00041 ACTOR15", getId() );

    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR16
//no valid quest var detected
if( result.param2 == 1 ){
//next scene not found
}
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00042 ACTOR16", getId() );

    player.playScene( getId(), 42, NONE, callback );
  }

};

EXPOSE_SCRIPT( ManFst407 );
