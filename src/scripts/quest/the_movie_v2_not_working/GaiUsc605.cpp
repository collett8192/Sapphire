// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsc605_01005
// Quest Name: Every Little Thing She Does Is Magitek
// Quest ID: 66541
// Start NPC: 1006555
// End NPC: 1006555

using namespace Sapphire;

class GaiUsc605 : public Sapphire::ScriptAPI::EventScript
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
//      Seq10 = 10,
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
//    static constexpr auto Actor0 = 1006555;
//    static constexpr auto Actor1 = 1006530;
//    static constexpr auto Actor2 = 1006557;
//    static constexpr auto Actor3 = 1004093;
//    static constexpr auto Actor4 = 1006559;
//    static constexpr auto Actor5 = 1006558;
//    static constexpr auto Actor6 = 1006560;
//    static constexpr auto Actor7 = 1006561;
//    static constexpr auto Eobject0 = 2002523;
//    static constexpr auto Eobject1 = 2002524;
//    static constexpr auto Eobject2 = 2002525;
//    static constexpr auto Eobject3 = 2002531;
//    static constexpr auto Eventrange0 = 4322856;
//    static constexpr auto Eventrange1 = 4322857;
//    static constexpr auto Eventrange2 = 4322858;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000772;
//    static constexpr auto LevelArmorId = 4265706;
//    static constexpr auto LevelBiggsId = 4265705;
//    static constexpr auto LevelCidId = 4265703;
//    static constexpr auto LevelWedgeId = 4265704;
//    static constexpr auto LinkSe1 = 42;
//    static constexpr auto LinkTalkshape1 = 6;
//    static constexpr auto LocAction0 = 1015;
//    static constexpr auto LocAction1 = 858;
//    static constexpr auto LocAction2 = 112;
//    static constexpr auto LocAction3 = 1005;
//    static constexpr auto LocActor0 = 1002908;
//    static constexpr auto LocActor1 = 1003837;
//    static constexpr auto LocActor2 = 1003855;
//    static constexpr auto LocActor3 = 1003836;
//    static constexpr auto LocActor9 = 1003075;
//    static constexpr auto LocFace0 = 604;
//    static constexpr auto LocFace1 = 605;
//    static constexpr auto LocFace2 = 620;
//    static constexpr auto LocPosActor0 = 4330073;
//    static constexpr auto LocPosActor1 = 4330075;
//    static constexpr auto LocSe1 = 46;
//    static constexpr auto Mount0 = 14;
//    static constexpr auto Poprange0 = 4321644;
//    static constexpr auto Poprange1 = 4322935;
//    static constexpr auto Questbattle0 = 64;
//    static constexpr auto Territorytype0 = 156;
//    static constexpr auto Territorytype1 = 309;

  public:
    GaiUsc605() : Sapphire::ScriptAPI::EventScript( 66541 ){}; 
    ~GaiUsc605() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1006555 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00000( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006530 ) { Scene00002( player ); }
break;
}
case 1:{
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1006557 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006530 ) { Scene00004( player ); }
break;
}
case 2:{
Scene00005( player );
break;
}
case 3:{
//ACTOR2, UI8AL, 1, -1, False
if( actor == 1006557 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00006( player ); }
//ACTOR1, null, 0, -1, False
if( actor == 1006530 ) { Scene00008( player ); }
break;
}
case 4:{
//ACTOR4, UI8AL, 1, -2, False
if( actor == 1006559 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00009( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1006558 ) { Scene00010( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1006560 ) { Scene00011( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1006561 ) { Scene00012( player ); }
break;
}
case 5:{
//if( actor == 1006558 ) { Scene?????( player ); }
//if( actor == 1006559 ) { Scene?????( player ); }
//if( actor == 1006560 ) { Scene?????( player ); }
//if( actor == 2002523 ) { Scene?????( player ); }
Scene00013( player );
break;
}
case 6:{
//if( actor == 1006558 ) { Scene?????( player ); }
//if( actor == 1006559 ) { Scene?????( player ); }
//if( actor == 1006560 ) { Scene?????( player ); }
//if( actor == 2002524 ) { Scene?????( player ); }
Scene00014( player );
break;
}
case 7:{
//if( actor == 1006558 ) { Scene?????( player ); }
//if( actor == 1006559 ) { Scene?????( player ); }
//if( actor == 1006560 ) { Scene?????( player ); }
//if( actor == 2002525 ) { Scene?????( player ); }
Scene00015( player );
break;
}
case 8:{
//ACTOR4, UI8AL, 1, -2, False
if( actor == 1006559 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00016( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1006558 ) { Scene00017( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1006560 ) { Scene00018( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1006561 ) { Scene00019( player ); }
break;
}
case 9:{
//ACTOR4, null, 0, -2, False
if( actor == 1006559 ) { Scene00020( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1006558 ) { Scene00021( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1006560 ) { Scene00022( player ); }
//ACTOR7, UI8AL, 1, -2, False
if( actor == 1006561 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00023( player ); }
break;
}
case 10:{
//ACTOR6, UI8AL, 1, -2, False
if( actor == 1006560 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00024( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1006558 ) { Scene00025( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1006559 ) { Scene00026( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1006561 ) { Scene00027( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002531 ) { Scene00028( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1006555 ) { Scene00050( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006530 ) { Scene00051( player ); }
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
//Target: ACTOR0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ACTOR0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
      if( result.param2 == 1 ){
        player.eventFinish( getId(), 1 );
        player.setPosAndSendActorMove( 0.64, -158.5, 13.4, 3.13 );
      }
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00002 ACTOR1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00004 ACTOR1", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00007( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00006 +1 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 4 );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](6)Talk, FadeOut:Scene00007 ACTOR2:UI8AL=-1, 1", getId() );

    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00008 ACTOR1", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
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
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR4:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ACTOR5", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 ACTOR6", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ACTOR7", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {


player.updateQuest( getId(), 6 );

player.sendDebug( "questId: {}, calling Empty:Scene00013 ", getId() );


  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 7 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 ", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {


player.updateQuest( getId(), 8 );

player.sendDebug( "questId: {}, calling Empty:Scene00015 ", getId() );


  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 9 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 ACTOR4:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ACTOR5", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 ACTOR6", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00019 ACTOR7", getId() );


  }

  void Scene00020( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00020 ACTOR4", getId() );


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
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 10 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00023 ACTOR7:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00024 ACTOR6:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00025 ACTOR5", getId() );


  }

  void Scene00026( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00026 ACTOR4", getId() );


  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00027 ACTOR7", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00028 EOBJECT3", getId() );


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


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00032 ", getId() );


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
player.sendDebug( "questId: {}, calling Talk:Scene00034 ", getId() );

    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00035 ", getId() );

    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00036 ", getId() );

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
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00038 ", getId() );

    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00039 ", getId() );

    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00040 ", getId() );

    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00041 ", getId() );

    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00042 ", getId() );

    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00043 ", getId() );

    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling QuestBattle, YesNo:Scene00044 ", getId() );

    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00045 ", getId() );

    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00046 ", getId() );

    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00047 ", getId() );

    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00048 ", getId() );


  }

  void Scene00049( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00049 ", getId() );


  }

  void Scene00050( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00050 ACTOR0", getId() );

    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
if( result.param2 == 1 ){
//next scene not found
}
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00051 ACTOR1", getId() );

    player.playScene( getId(), 51, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsc605 );
