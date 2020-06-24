// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse316_01457
// Quest Name: Recruiting the Realm
// Quest ID: 66993
// Start NPC: 1009021
// End NPC: 1009021

using namespace Sapphire;

class GaiUse316 : public Sapphire::ScriptAPI::EventScript
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
//      Seq4 = 4,
//      Seq5 = 5,
//      Seq6 = 6,
//      Seq7 = 7,
//      Seq8 = 8,
//      Seq9 = 9,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1009021;
//    static constexpr auto Actor1 = 1009128;
//    static constexpr auto Actor10 = 1009139;
//    static constexpr auto Actor11 = 1000248;
//    static constexpr auto Actor12 = 1006263;
//    static constexpr auto Actor13 = 1009140;
//    static constexpr auto Actor14 = 1009131;
//    static constexpr auto Actor15 = 1009132;
//    static constexpr auto Actor16 = 1009135;
//    static constexpr auto Actor17 = 1009136;
//    static constexpr auto Actor18 = 1001679;
//    static constexpr auto Actor19 = 1001657;
//    static constexpr auto Actor2 = 1009133;
//    static constexpr auto Actor20 = 1001691;
//    static constexpr auto Actor3 = 1003282;
//    static constexpr auto Actor4 = 1000915;
//    static constexpr auto Actor5 = 1000918;
//    static constexpr auto Actor6 = 1001000;
//    static constexpr auto Actor7 = 1009129;
//    static constexpr auto Actor8 = 1009130;
//    static constexpr auto Actor9 = 1009138;
//    static constexpr auto CutSceneN01 = 538;
//    static constexpr auto LocAction1 = 1041;
//    static constexpr auto LocActor0 = 1004145;
//    static constexpr auto LocFace1 = 605;
//    static constexpr auto LocFace2 = 617;

  public:
    GaiUse316() : Sapphire::ScriptAPI::EventScript( 66993 ){}; 
    ~GaiUse316() = default; 

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
//ACTOR2, UI8AL, 5, -2, False
if( actor == 1009133 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00003( player ); }
//ACTOR3, UI8AL, 5, -2, False
if( actor == 1003282 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00004( player ); }
//ACTOR4, UI8AL, 5, -2, False
if( actor == 1000915 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00005( player ); }
//ACTOR5, UI8AL, 5, -2, False
if( actor == 1000918 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00006( player ); }
//ACTOR6, UI8AL, 5, -2, False
if( actor == 1001000 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00007( player ); }
break;
}
case 3:{
Scene00008( player );
break;
}
case 4:{
Scene00009( player );
break;
}
case 5:{
//ACTOR9, UI8AL, 4, -2, False
if( actor == 1009138 && player.getQuestUI8AL( getId() ) != 4 ) { Scene00010( player ); }
//ACTOR10, UI8AL, 4, -2, False
if( actor == 1009139 && player.getQuestUI8AL( getId() ) != 4 ) { Scene00011( player ); }
//ACTOR11, UI8AL, 4, -2, False
if( actor == 1000248 && player.getQuestUI8AL( getId() ) != 4 ) { Scene00012( player ); }
//ACTOR12, UI8AL, 4, -2, False
if( actor == 1006263 && player.getQuestUI8AL( getId() ) != 4 ) { Scene00013( player ); }
//ACTOR13, null, 0, -2, False
if( actor == 1009140 ) { Scene00014( player ); }
break;
}
case 6:{
//ACTOR14, UI8AL, 1, -2, False
if( actor == 1009131 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00015( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1009139 ) { Scene00016( player ); }
//ACTOR13, null, 0, -2, False
if( actor == 1009140 ) { Scene00017( player ); }
break;
}
case 7:{
Scene00018( player );
break;
}
case 8:{
//ACTOR16, UI8AL, 5, -2, False
if( actor == 1009135 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00019( player ); }
//ACTOR17, UI8AL, 5, -2, False
if( actor == 1009136 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00020( player ); }
//ACTOR18, UI8AL, 5, -2, False
if( actor == 1001679 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00021( player ); }
//ACTOR19, UI8AL, 5, -2, False
if( actor == 1001657 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00022( player ); }
//ACTOR20, UI8AL, 5, -2, False
if( actor == 1001691 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00023( player ); }
break;
}
case 9:{
//ACTOR15, UI8AL, 1, -2, False
if( actor == 1009132 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00024( player ); }
//ACTOR17, null, 0, -2, False
if( actor == 1009136 ) { Scene00025( player ); }
break;
}
case 255:{
Scene00038( player );
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
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR2:UI8AL=-2, 5", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR3:UI8AL=-2, 5", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ACTOR4:UI8AL=-2, 5", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00006 ACTOR5:UI8AL=-2, 5", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR6:UI8AL=-2, 5", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 5 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 4 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 6 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ACTOR9:UI8AL=-2, 4", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 4 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 6 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 ACTOR10:UI8AL=-2, 4", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR11
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 4 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 6 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ACTOR11:UI8AL=-2, 4", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR12
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 4 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 6 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 ACTOR12:UI8AL=-2, 4", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR13
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 ACTOR13", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR14
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 7 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 ACTOR14:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 ACTOR10", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR13
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ACTOR13", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 8 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 ", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR16
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 9 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00019 ACTOR16:UI8AL=-2, 5", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR17
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 9 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00020 ACTOR17:UI8AL=-2, 5", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR18
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 9 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00021 ACTOR18:UI8AL=-2, 5", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR19
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 9 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00022 ACTOR19:UI8AL=-2, 5", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR20
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 9 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00023 ACTOR20:UI8AL=-2, 5", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR15
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00024 ACTOR15:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR17
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00025 ACTOR17", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00026 ", getId() );

    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00027 ", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00028 ", getId() );

    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00029 ", getId() );

    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00030 ", getId() );

    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00031 ", getId() );

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
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00033 ", getId() );

    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00034 ", getId() );

    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00036( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00035 +1 ", getId() );

    player.playScene( getId(), 35, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00037 ", getId() );

    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00038 ", getId() );

    player.playScene( getId(), 38, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse316 );
