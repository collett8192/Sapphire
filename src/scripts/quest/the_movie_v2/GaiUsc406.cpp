// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: True, A2: True, A3: False, S: True, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsc406_00981
// Quest Name: Footprints in the Snow
// Quest ID: 66517
// Start NPC: 1006518
// End NPC: 1006521

using namespace Sapphire;

class GaiUsc406 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006518;
//    static constexpr auto Actor1 = 1006519;
//    static constexpr auto Actor2 = 1006521;
//    static constexpr auto Eobject0 = 2002196;
//    static constexpr auto Eobject1 = 2002681;
//    static constexpr auto Eobject2 = 2002682;
//    static constexpr auto Eobject3 = 2002683;
//    static constexpr auto Eobject4 = 2002684;
//    static constexpr auto Eobject5 = 2002685;
//    static constexpr auto Eobject6 = 2002197;
//    static constexpr auto Eobject7 = 2002198;
//    static constexpr auto Eobject8 = 2002199;
//    static constexpr auto Eobject9 = 2002200;
//    static constexpr auto EventActionLookoutLong = 41;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto LocAction1 = 936;
//    static constexpr auto LocAction2 = 985;
//    static constexpr auto LocAction3 = 1002;
//    static constexpr auto LocActor0 = 1003837;
//    static constexpr auto LocActor1 = 1003855;
//    static constexpr auto LocBgm1 = 93;
//    static constexpr auto LocPosActor0 = 4322708;
//    static constexpr auto LocPosActor1 = 4273899;
//    static constexpr auto LocSe1 = 42;
//    static constexpr auto LocTalkshape1 = 6;

  public:
    GaiUsc406() : Sapphire::ScriptAPI::EventScript( 66517 ){}; 
    ~GaiUsc406() = default; 

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
//EOBJECT0, UI8AL, 1, -2, False
if( actor == 2002196 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002681 ) { Scene00004( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002682 ) { Scene00006( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002683 ) { Scene00008( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002684 ) { Scene00010( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002685 ) { Scene00012( player ); }
break;
}
case 2:{
//EOBJECT6, UI8AL, 1, -2, False
if( actor == 2002197 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00014( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002681 ) { Scene00016( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002682 ) { Scene00018( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002683 ) { Scene00020( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002684 ) { Scene00022( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002685 ) { Scene00024( player ); }
break;
}
case 3:{
//EOBJECT7, UI8AL, 1, -2, False
if( actor == 2002198 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00026( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002681 ) { Scene00028( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002682 ) { Scene00030( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002683 ) { Scene00032( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002684 ) { Scene00034( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002685 ) { Scene00036( player ); }
break;
}
case 4:{
//EOBJECT8, UI8AL, 1, -2, False
if( actor == 2002199 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00038( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002681 ) { Scene00040( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002682 ) { Scene00042( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002683 ) { Scene00044( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002684 ) { Scene00046( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002685 ) { Scene00048( player ); }
break;
}
case 5:{
//EOBJECT9, UI8AL, 1, -2, False
if( actor == 2002200 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00050( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002681 ) { Scene00052( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002682 ) { Scene00054( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002683 ) { Scene00056( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002684 ) { Scene00058( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002685 ) { Scene00060( player ); }
break;
}
case 6:{
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1006519 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00062( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002681 ) { Scene00063( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002682 ) { Scene00065( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002683 ) { Scene00067( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002684 ) { Scene00069( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002685 ) { Scene00071( player ); }
break;
}
case 255:{
//ACTOR2, null, 0, -2, False
if( actor == 1006521 ) { Scene00073( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002681 ) { Scene00074( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002682 ) { Scene00076( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002683 ) { Scene00078( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002684 ) { Scene00080( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002685 ) { Scene00082( player ); }
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
{ Scene00003( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00002 +1 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](2)Empty:Scene00003 EOBJECT0:UI8AL=-2, 1", getId() );


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


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](4)Empty:Scene00005 EOBJECT1", getId() );


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


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](6)Empty:Scene00007 EOBJECT2", getId() );


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


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](8)Empty:Scene00009 EOBJECT3", getId() );


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


//Target: EOBJECT4
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](10)Empty:Scene00011 EOBJECT4", getId() );


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


//Target: EOBJECT5
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](12)Empty:Scene00013 EOBJECT5", getId() );


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


//Target: EOBJECT6
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](14)Empty:Scene00015 EOBJECT6:UI8AL=-2, 1", getId() );


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


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](16)Empty:Scene00017 EOBJECT1", getId() );


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


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](18)Empty:Scene00019 EOBJECT2", getId() );


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


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](20)Empty:Scene00021 EOBJECT3", getId() );


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


//Target: EOBJECT4
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](22)Empty:Scene00023 EOBJECT4", getId() );


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


//Target: EOBJECT5
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](24)Empty:Scene00025 EOBJECT5", getId() );


  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00027( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00026 +1 ", getId() );

    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {


//Target: EOBJECT7
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 4 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](26)Empty:Scene00027 EOBJECT7:UI8AL=-2, 1", getId() );


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


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](28)Empty:Scene00029 EOBJECT1", getId() );


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


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](30)Empty:Scene00031 EOBJECT2", getId() );


  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00033( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00032 +1 ", getId() );

    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](32)Empty:Scene00033 EOBJECT3", getId() );


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


//Target: EOBJECT4
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](34)Empty:Scene00035 EOBJECT4", getId() );


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


//Target: EOBJECT5
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](36)Empty:Scene00037 EOBJECT5", getId() );


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


//Target: EOBJECT8
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 5 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](38)Empty:Scene00039 EOBJECT8:UI8AL=-2, 1", getId() );


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


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](40)Empty:Scene00041 EOBJECT1", getId() );


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


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](42)Empty:Scene00043 EOBJECT2", getId() );


  }

  void Scene00044( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00045( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00044 +1 ", getId() );

    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](44)Empty:Scene00045 EOBJECT3", getId() );


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


//Target: EOBJECT4
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](46)Empty:Scene00047 EOBJECT4", getId() );


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


//Target: EOBJECT5
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](48)Empty:Scene00049 EOBJECT5", getId() );


  }

  void Scene00050( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00051( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00050 +1 ", getId() );

    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {


//Target: EOBJECT9
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 6 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](50)Empty:Scene00051 EOBJECT9:UI8AL=-2, 1", getId() );


  }

  void Scene00052( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00053( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00052 +1 ", getId() );

    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](52)Empty:Scene00053 EOBJECT1", getId() );


  }

  void Scene00054( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00055( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00054 +1 ", getId() );

    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](54)Empty:Scene00055 EOBJECT2", getId() );


  }

  void Scene00056( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00057( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00056 +1 ", getId() );

    player.playScene( getId(), 56, NONE, callback );
  }

  void Scene00057( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](56)Empty:Scene00057 EOBJECT3", getId() );


  }

  void Scene00058( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00059( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00058 +1 ", getId() );

    player.playScene( getId(), 58, NONE, callback );
  }

  void Scene00059( Entity::Player& player )
  {


//Target: EOBJECT4
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](58)Empty:Scene00059 EOBJECT4", getId() );


  }

  void Scene00060( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00061( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00060 +1 ", getId() );

    player.playScene( getId(), 60, NONE, callback );
  }

  void Scene00061( Entity::Player& player )
  {


//Target: EOBJECT5
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](60)Empty:Scene00061 EOBJECT5", getId() );


  }

  void Scene00062( Entity::Player& player )
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
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00062 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 62, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00063( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00064( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00063 +1 ", getId() );

    player.playScene( getId(), 63, NONE, callback );
  }

  void Scene00064( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](63)Empty:Scene00064 EOBJECT1", getId() );


  }

  void Scene00065( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00066( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00065 +1 ", getId() );

    player.playScene( getId(), 65, NONE, callback );
  }

  void Scene00066( Entity::Player& player )
  {


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](65)Empty:Scene00066 EOBJECT2", getId() );


  }

  void Scene00067( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00068( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00067 +1 ", getId() );

    player.playScene( getId(), 67, NONE, callback );
  }

  void Scene00068( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](67)Empty:Scene00068 EOBJECT3", getId() );


  }

  void Scene00069( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00070( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00069 +1 ", getId() );

    player.playScene( getId(), 69, NONE, callback );
  }

  void Scene00070( Entity::Player& player )
  {


//Target: EOBJECT4
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](69)Empty:Scene00070 EOBJECT4", getId() );


  }

  void Scene00071( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00072( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00071 +1 ", getId() );

    player.playScene( getId(), 71, NONE, callback );
  }

  void Scene00072( Entity::Player& player )
  {


//Target: EOBJECT5
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](71)Empty:Scene00072 EOBJECT5", getId() );


  }

  void Scene00073( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete, FadeOut:Scene00073 ACTOR2", getId() );

    player.playScene( getId(), 73, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00074( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00075( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00074 +1 ", getId() );

    player.playScene( getId(), 74, NONE, callback );
  }

  void Scene00075( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](74)Empty:Scene00075 EOBJECT1", getId() );


  }

  void Scene00076( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00077( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00076 +1 ", getId() );

    player.playScene( getId(), 76, NONE, callback );
  }

  void Scene00077( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](76)Empty:Scene00077 EOBJECT2", getId() );


  }

  void Scene00078( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00079( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00078 +1 ", getId() );

    player.playScene( getId(), 78, NONE, callback );
  }

  void Scene00079( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](78)Empty:Scene00079 EOBJECT3", getId() );


  }

  void Scene00080( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00081( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00080 +1 ", getId() );

    player.playScene( getId(), 80, NONE, callback );
  }

  void Scene00081( Entity::Player& player )
  {


//Target: EOBJECT4
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](80)Empty:Scene00081 EOBJECT4", getId() );


  }

  void Scene00082( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00083( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00082 +1 ", getId() );

    player.playScene( getId(), 82, NONE, callback );
  }

  void Scene00083( Entity::Player& player )
  {


//Target: EOBJECT5
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](82)Empty:Scene00083 EOBJECT5", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsc406 );
