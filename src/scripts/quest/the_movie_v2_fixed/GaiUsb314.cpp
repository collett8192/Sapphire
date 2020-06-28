// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: True, S: True, R: False, DM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb314_00855
// Quest Name: In the Company of Heroes
// Quest ID: 66391
// Start NPC: 1006676
// End NPC: 1006676

using namespace Sapphire;

class GaiUsb314 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag16
    // GetQuestUI8AH
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL
    // GetQuestUI8CH
    // GetQuestUI8CL

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
//    static constexpr auto Actor0 = 1006676;
//    static constexpr auto Actor1 = 1006314;
//    static constexpr auto Actor2 = 1006313;
//    static constexpr auto Actor3 = 1006315;
//    static constexpr auto Actor4 = 1006316;
//    static constexpr auto Actor5 = 1006317;
//    static constexpr auto Actor6 = 1006318;
//    static constexpr auto Actor7 = 1006319;
//    static constexpr auto Actor8 = 1006266;
//    static constexpr auto BgmLvup = 23;
//    static constexpr auto CutScene01 = 369;
//    static constexpr auto Eobject0 = 2002075;
//    static constexpr auto Eobject1 = 2002076;
//    static constexpr auto Eobject2 = 2002077;
//    static constexpr auto Eobject3 = 2002078;
//    static constexpr auto Eobject4 = 2002079;
//    static constexpr auto Eobject5 = 2002080;
//    static constexpr auto Eobject6 = 2002081;
//    static constexpr auto Eobject7 = 2002082;
//    static constexpr auto Eobject8 = 2002598;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto LocAction0 = 788;
//    static constexpr auto LocAction1 = 1016;
//    static constexpr auto LocAction2 = 683;
//    static constexpr auto LocActor1 = 1006272;
//    static constexpr auto LocEobj1 = 2002687;
//    static constexpr auto LocPosActor0 = 4374246;
//    static constexpr auto LocPosActor1 = 4258358;
//    static constexpr auto LocPosCam1 = 4374251;
//    static constexpr auto LocPosEobj1 = 4373897;

  public:
    GaiUsb314() : Sapphire::ScriptAPI::EventScript( 66391 ){}; 
    ~GaiUsb314() = default; 

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
if( actor == 1006314 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006313 ) { Scene00004( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006315 ) { Scene00005( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1006316 ) { Scene00006( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1006317 ) { Scene00007( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1006318 ) { Scene00008( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1006319 ) { Scene00009( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002075 ) { Scene00010( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002076 ) { Scene00012( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002077 ) { Scene00014( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002078 ) { Scene00016( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002079 ) { Scene00018( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002080 ) { Scene00020( player ); }
//EOBJECT6, null, 0, -2, False
if( actor == 2002081 ) { Scene00022( player ); }
//EOBJECT7, null, 0, -2, False
if( actor == 2002082 ) { Scene00024( player ); }
break;
}
case 2:{
//EOBJECT8, UI8AL, 1, -2, False
if( actor == 2002598 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00027( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006313 ) { Scene00028( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006314 ) { Scene00029( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006315 ) { Scene00030( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1006316 ) { Scene00031( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1006317 ) { Scene00032( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1006318 ) { Scene00033( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1006319 ) { Scene00034( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002075 ) { Scene00035( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002076 ) { Scene00037( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002077 ) { Scene00039( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002078 ) { Scene00041( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002079 ) { Scene00043( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002080 ) { Scene00045( player ); }
//EOBJECT6, null, 0, -2, False
if( actor == 2002081 ) { Scene00047( player ); }
//EOBJECT7, null, 0, -2, False
if( actor == 2002082 ) { Scene00049( player ); }
break;
}
case 3:{
//ACTOR8, UI8AL, 1, -2, False
if( actor == 1006266 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00051( player ); }
//ACTOR5, UI8BH, 1, -2, False
if( actor == 1006317 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00053( player ); }
//ACTOR4, UI8BL, 1, -2, False
if( actor == 1006316 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00055( player ); }
//ACTOR6, UI8CH, 1, -2, False
if( actor == 1006318 && player.getQuestUI8CH( getId() ) != 1 ) { Scene00057( player ); }
//ACTOR7, UI8CL, 1, -2, False
if( actor == 1006319 && player.getQuestUI8CL( getId() ) != 1 ) { Scene00059( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006313 ) { Scene00062( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006314 ) { Scene00063( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006315 ) { Scene00064( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002078 ) { Scene00066( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002079 ) { Scene00068( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002080 ) { Scene00070( player ); }
//EOBJECT6, null, 0, -2, False
if( actor == 2002081 ) { Scene00072( player ); }
//EOBJECT7, null, 0, -2, False
if( actor == 2002082 ) { Scene00074( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1006676 ) { Scene00075( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006313 ) { Scene00076( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006314 ) { Scene00077( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006315 ) { Scene00078( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1006316 ) { Scene00079( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1006317 ) { Scene00080( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1006318 ) { Scene00081( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1006319 ) { Scene00082( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002078 ) { Scene00083( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002079 ) { Scene00085( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002080 ) { Scene00087( player ); }
//EOBJECT6, null, 0, -2, False
if( actor == 2002081 ) { Scene00089( player ); }
//EOBJECT7, null, 0, -2, False
if( actor == 2002082 ) { Scene00091( player ); }
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
player.sendDebug( "questId: {}, calling [sub:Intro](0)Talk:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)QuestAccept, CutScene:Scene00002 ", getId() );

    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
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
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR2", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ACTOR3", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00006 ACTOR4", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR5", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR6", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR7", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00011( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00010 +1 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](10)Empty:Scene00011 EOBJECT0", getId() );


  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00013( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00012 +1 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](12)Empty:Scene00013 EOBJECT1", getId() );


  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00015( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00014 +1 ", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](14)Empty:Scene00015 EOBJECT2", getId() );


  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00017( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00016 +1 ", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](16)Empty:Scene00017 EOBJECT3", getId() );


  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00019( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00018 +1 ", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {


//Target: EOBJECT4
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](18)Empty:Scene00019 EOBJECT4", getId() );


  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00021( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00020 +1 ", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {


//Target: EOBJECT5
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](20)Empty:Scene00021 EOBJECT5", getId() );


  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00023( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00022 +1 ", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {


//Target: EOBJECT6
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](22)Empty:Scene00023 EOBJECT6", getId() );


  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00025( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00024 +1 ", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {


//Target: EOBJECT7
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](24)Empty:Scene00025 EOBJECT7", getId() );


  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT8
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00027 EOBJECT8:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00028 ACTOR2", getId() );

    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00029 ACTOR1", getId() );

    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00030 ACTOR3", getId() );

    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00031 ACTOR4", getId() );

    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00032 ACTOR5", getId() );

    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00033 ACTOR6", getId() );

    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00034 ACTOR7", getId() );

    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00036( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00035 +1 ", getId() );

    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](35)Empty:Scene00036 EOBJECT0", getId() );


  }

  void Scene00037( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00038( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00037 +1 ", getId() );

    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](37)Empty:Scene00038 EOBJECT1", getId() );


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


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](39)Empty:Scene00040 EOBJECT2", getId() );


  }

  void Scene00041( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00042( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00041 +1 ", getId() );

    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](41)Empty:Scene00042 EOBJECT3", getId() );


  }

  void Scene00043( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00044( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00043 +1 ", getId() );

    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {


//Target: EOBJECT4
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](43)Empty:Scene00044 EOBJECT4", getId() );


  }

  void Scene00045( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00046( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00045 +1 ", getId() );

    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {


//Target: EOBJECT5
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](45)Empty:Scene00046 EOBJECT5", getId() );


  }

  void Scene00047( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00048( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00047 +1 ", getId() );

    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {


//Target: EOBJECT6
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](47)Empty:Scene00048 EOBJECT6", getId() );


  }

  void Scene00049( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00050( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00049 +1 ", getId() );

    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {


//Target: EOBJECT7
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](49)Empty:Scene00050 EOBJECT7", getId() );


  }

  void Scene00051( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00051 ACTOR8:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00053 ACTOR5:UI8BH=-2, 1", getId() );

    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00055 ACTOR4:UI8BL=-2, 1", getId() );

    player.playScene( getId(), 55, NONE, callback );
  }

  void Scene00056( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 56, NONE, callback );
  }

  void Scene00057( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
player.setQuestUI8CH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00057 ACTOR6:UI8CH=-2, 1", getId() );

    player.playScene( getId(), 57, NONE, callback );
  }

  void Scene00058( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 58, NONE, callback );
  }

  void Scene00059( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
player.setQuestUI8CL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00059 ACTOR7:UI8CL=-2, 1", getId() );

    player.playScene( getId(), 59, NONE, callback );
  }

  void Scene00060( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 60, NONE, callback );
  }

  void Scene00061( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 61, NONE, callback );
  }

  void Scene00062( Entity::Player& player )
  {


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00062 ACTOR2", getId() );


  }

  void Scene00063( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00063 ACTOR1", getId() );

    player.playScene( getId(), 63, NONE, callback );
  }

  void Scene00064( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00065( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00064 +1 ", getId() );

    player.playScene( getId(), 64, NONE, callback );
  }

  void Scene00065( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](64)Empty:Scene00065 ACTOR3", getId() );


  }

  void Scene00066( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00067( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00066 +1 ", getId() );

    player.playScene( getId(), 66, NONE, callback );
  }

  void Scene00067( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](66)Empty:Scene00067 EOBJECT3", getId() );


  }

  void Scene00068( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00069( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00068 +1 ", getId() );

    player.playScene( getId(), 68, NONE, callback );
  }

  void Scene00069( Entity::Player& player )
  {


//Target: EOBJECT4
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](68)Empty:Scene00069 EOBJECT4", getId() );


  }

  void Scene00070( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00071( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00070 +1 ", getId() );

    player.playScene( getId(), 70, NONE, callback );
  }

  void Scene00071( Entity::Player& player )
  {


//Target: EOBJECT5
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](70)Empty:Scene00071 EOBJECT5", getId() );


  }

  void Scene00072( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00073( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00072 +1 ", getId() );

    player.playScene( getId(), 72, NONE, callback );
  }

  void Scene00073( Entity::Player& player )
  {


//Target: EOBJECT6
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](72)Empty:Scene00073 EOBJECT6", getId() );


  }

  void Scene00074( Entity::Player& player )
  {


//Target: EOBJECT7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00074 EOBJECT7", getId() );


  }

  void Scene00075( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete, FadeOut:Scene00075 ACTOR0", getId() );

    player.playScene( getId(), 75, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00076( Entity::Player& player )
  {


//Target: ACTOR2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00076 ACTOR2", getId() );


  }

  void Scene00077( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00077 ACTOR1", getId() );

    player.playScene( getId(), 77, NONE, callback );
  }

  void Scene00078( Entity::Player& player )
  {


//Target: ACTOR3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00078 ACTOR3", getId() );


  }

  void Scene00079( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00079 ACTOR4", getId() );

    player.playScene( getId(), 79, NONE, callback );
  }

  void Scene00080( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00080 ACTOR5", getId() );

    player.playScene( getId(), 80, NONE, callback );
  }

  void Scene00081( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00081 ACTOR6", getId() );

    player.playScene( getId(), 81, NONE, callback );
  }

  void Scene00082( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00082 ACTOR7", getId() );

    player.playScene( getId(), 82, NONE, callback );
  }

  void Scene00083( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00084( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00083 +1 ", getId() );

    player.playScene( getId(), 83, NONE, callback );
  }

  void Scene00084( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](83)Empty:Scene00084 EOBJECT3", getId() );


  }

  void Scene00085( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00086( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00085 +1 ", getId() );

    player.playScene( getId(), 85, NONE, callback );
  }

  void Scene00086( Entity::Player& player )
  {


//Target: EOBJECT4
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](85)Empty:Scene00086 EOBJECT4", getId() );


  }

  void Scene00087( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00088( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00087 +1 ", getId() );

    player.playScene( getId(), 87, NONE, callback );
  }

  void Scene00088( Entity::Player& player )
  {


//Target: EOBJECT5
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](87)Empty:Scene00088 EOBJECT5", getId() );


  }

  void Scene00089( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00090( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00089 +1 ", getId() );

    player.playScene( getId(), 89, NONE, callback );
  }

  void Scene00090( Entity::Player& player )
  {


//Target: EOBJECT6
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](89)Empty:Scene00090 EOBJECT6", getId() );


  }

  void Scene00091( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00092( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00091 +1 ", getId() );

    player.playScene( getId(), 91, NONE, callback );
  }

  void Scene00092( Entity::Player& player )
  {


//Target: EOBJECT7
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](91)Empty:Scene00092 EOBJECT7", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsb314 );
