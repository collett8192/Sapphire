// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse203_01347
// Quest Name: The Mother of Exiles
// Quest ID: 66883
// Start NPC: 1008597
// End NPC: 1008616

using namespace Sapphire;

class GaiUse203 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL
    // GetQuestUI8CH

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
//      Seq7 = 7,
//      Seq8 = 8,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1008597;
//    static constexpr auto Actor1 = 1008600;
//    static constexpr auto Actor10 = 1008608;
//    static constexpr auto Actor11 = 1008609;
//    static constexpr auto Actor12 = 1008610;
//    static constexpr auto Actor13 = 1001353;
//    static constexpr auto Actor14 = 1001966;
//    static constexpr auto Actor15 = 1001968;
//    static constexpr auto Actor16 = 1008616;
//    static constexpr auto Actor17 = 1008612;
//    static constexpr auto Actor18 = 1008613;
//    static constexpr auto Actor19 = 1008614;
//    static constexpr auto Actor2 = 1008602;
//    static constexpr auto Actor20 = 1008615;
//    static constexpr auto Actor21 = 1008617;
//    static constexpr auto Actor3 = 1008603;
//    static constexpr auto Actor4 = 1001821;
//    static constexpr auto Actor5 = 1008601;
//    static constexpr auto Actor6 = 1008604;
//    static constexpr auto Actor7 = 1008605;
//    static constexpr auto Actor8 = 1008606;
//    static constexpr auto Actor9 = 1008607;
//    static constexpr auto CutSceneN01 = 461;
//    static constexpr auto CutSceneN02 = 462;
//    static constexpr auto Eventrange0 = 4663959;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2001202;
//    static constexpr auto Item1 = 2001203;
//    static constexpr auto LocActor1 = 1007768;
//    static constexpr auto LocActor2 = 1007098;
//    static constexpr auto LocActor3 = 1007099;
//    static constexpr auto LocActor4 = 1001821;
//    static constexpr auto LocActor5 = 1007097;
//    static constexpr auto LocFace0 = 605;
//    static constexpr auto LocPosActor0 = 4678064;
//    static constexpr auto LocPosActor1 = 4635471;
//    static constexpr auto LocPosActor2 = 4635472;
//    static constexpr auto LocPosActor3 = 4635473;

  public:
    GaiUse203() : Sapphire::ScriptAPI::EventScript( 66883 ){}; 
    ~GaiUse203() = default; 

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
if( actor == 1008600 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1008597 ) { Scene00003( player ); }
break;
}
case 2:{
//ACTOR2, null, 0, -2, False
if( actor == 1008602 ) { Scene00004( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008603 ) { Scene00005( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1001821 ) { Scene00006( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1008601 ) { Scene00007( player ); }
break;
}
case 3:{
//ACTOR6, UI8AL, 1, -2, False
if( actor == 1008604 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00008( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1008605 ) { Scene00010( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1008606 ) { Scene00011( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1008607 ) { Scene00012( player ); }
break;
}
case 4:{
//ACTOR10, UI8AL, 1, -2, False
if( actor == 1008608 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00013( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1008609 ) { Scene00014( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1008610 ) { Scene00015( player ); }
break;
}
case 5:{
//ACTOR13, UI8AL, 1, -2, False
if( actor == 1001353 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00016( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1008608 ) { Scene00017( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1008609 ) { Scene00018( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1008610 ) { Scene00019( player ); }
break;
}
case 6:{
//ACTOR14, UI8BH, 1, -1, False
if( actor == 1001966 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00020( player ); }
//ACTOR15, UI8AL, 1, -1, False
if( actor == 1001968 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00022( player ); }
//ACTOR10, null, 0, -1, False
if( actor == 1008608 ) { Scene00025( player ); }
//ACTOR11, null, 0, -1, False
if( actor == 1008609 ) { Scene00026( player ); }
//ACTOR12, null, 0, -1, False
if( actor == 1008610 ) { Scene00027( player ); }
break;
}
case 7:{
//ACTOR13, UI8AL, 1, -2, False
if( actor == 1001353 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00028( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1008608 ) { Scene00029( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1008609 ) { Scene00030( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1008610 ) { Scene00031( player ); }
break;
}
case 8:{
//ACTOR10, UI8AL, 1, -2, False
if( actor == 1008608 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00032( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1008609 ) { Scene00033( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1008610 ) { Scene00034( player ); }
break;
}
case 255:{
//ACTOR16, null, 0, -2, False
if( actor == 1008616 ) { Scene00037( player ); }
//ACTOR17, null, 0, -2, False
if( actor == 1008612 ) { Scene00038( player ); }
//ACTOR18, null, 0, -2, False
if( actor == 1008613 ) { Scene00039( player ); }
//ACTOR19, null, 0, -2, False
if( actor == 1008614 ) { Scene00040( player ); }
//ACTOR20, null, 0, -2, False
if( actor == 1008615 ) { Scene00041( player ); }
//ACTOR21, null, 0, -2, False
if( actor == 1008617 ) { Scene00042( player ); }
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
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00004 ACTOR2", getId() );

    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ACTOR3", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00006 ACTOR4", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR5", getId() );

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
//Target: ACTOR6
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 4 );
}
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](8)CutScene:Scene00009 ACTOR6:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ACTOR7", getId() );

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
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ACTOR9", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 5 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 ACTOR10:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR11
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 ACTOR11", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR12
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 ACTOR12", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR13
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 6 );
player.setQuestUI8BL( getId(), 1 );
player.setQuestUI8CH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 ACTOR13:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ACTOR10", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR11
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 ACTOR11", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR12
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00019 ACTOR12", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00021( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00020 +1 ", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR14
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 7 );
}
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](20)Talk:Scene00021 ACTOR14:UI8BH=-1, 1", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00023( player ); }
 else { Scene00024( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00022 +2 ", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR15
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 7 );
}
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](22)Talk:Scene00023 ACTOR15:UI8AL=-1, 1", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](22)Talk:Scene00024 ", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00025 ACTOR10", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR11
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00026 ACTOR11", getId() );

    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR12
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00027 ACTOR12", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR13
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 8 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00028 ACTOR13:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00029 ACTOR10", getId() );

    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR11
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00030 ACTOR11", getId() );

    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR12
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00031 ACTOR12", getId() );

    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00032 ACTOR10:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 32, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR11
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00033 ACTOR11", getId() );

    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR12
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00034 ACTOR12", getId() );

    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00036( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00035 +1 ", getId() );

    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](35)CutScene:Scene00036 ", getId() );

    player.playScene( getId(), 36, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling QuestReward, QuestComplete, FadeOut:Scene00037 ACTOR16", getId() );

    player.playScene( getId(), 37, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR17
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00038 ACTOR17", getId() );

    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR18
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00039 ACTOR18", getId() );

    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR19
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00040 ACTOR19", getId() );

    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR20
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00041 ACTOR20", getId() );

    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR21
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00042 ACTOR21", getId() );

    player.playScene( getId(), 42, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse203 );
