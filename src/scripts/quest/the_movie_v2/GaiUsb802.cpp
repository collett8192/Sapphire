// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: True, S: True, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb802_00911
// Quest Name: Following the Evidence
// Quest ID: 66447
// Start NPC: 1006384
// End NPC: 1006384

using namespace Sapphire;

class GaiUsb802 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag16
    // GetQuestBitFlag8
    // GetQuestUI8AH
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006384;
//    static constexpr auto Actor1 = 1006412;
//    static constexpr auto Actor2 = 1006413;
//    static constexpr auto Actor3 = 1006414;
//    static constexpr auto Eobject0 = 2002137;
//    static constexpr auto Eobject1 = 2002138;
//    static constexpr auto Eobject2 = 2002139;
//    static constexpr auto Eobject3 = 2002141;
//    static constexpr auto Eobject4 = 2002140;
//    static constexpr auto Eobject5 = 2002678;
//    static constexpr auto Eobject6 = 2002679;
//    static constexpr auto Eobject7 = 2002680;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000711;

  public:
    GaiUsb802() : Sapphire::ScriptAPI::EventScript( 66447 ){}; 
    ~GaiUsb802() = default; 

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
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1006413 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006414 ) { Scene00004( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002137 ) { Scene00005( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002138 ) { Scene00007( player ); }
break;
}
case 3:{
//EOBJECT2, UI8BH, 1, -2, False
if( actor == 2002139 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00009( player ); }
//EOBJECT3, UI8AL, 1, -2, False
if( actor == 2002141 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00011( player ); }
//EOBJECT4, UI8BL, 1, -2, False
if( actor == 2002140 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00013( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002137 ) { Scene00015( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002138 ) { Scene00017( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006413 ) { Scene00019( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006414 ) { Scene00020( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002678 ) { Scene00021( player ); }
//EOBJECT6, null, 0, -2, False
if( actor == 2002679 ) { Scene00023( player ); }
//EOBJECT7, null, 0, -2, False
if( actor == 2002680 ) { Scene00025( player ); }
break;
}
case 4:{
//ACTOR2, UI8AL, 1, -1, False
if( actor == 1006413 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00027( player ); }
//EOBJECT0, null, 0, -1, False
if( actor == 2002137 ) { Scene00029( player ); }
//EOBJECT1, null, 0, -1, False
if( actor == 2002138 ) { Scene00031( player ); }
//ACTOR3, null, 0, -1, False
if( actor == 1006414 ) { Scene00033( player ); }
//EOBJECT5, null, 0, -1, False
if( actor == 2002678 ) { Scene00034( player ); }
//EOBJECT6, null, 0, -1, False
if( actor == 2002679 ) { Scene00036( player ); }
//EOBJECT7, null, 0, -1, False
if( actor == 2002680 ) { Scene00038( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -1, False
if( actor == 1006384 ) { Scene00040( player ); }
//EOBJECT1, null, 0, -1, False
if( actor == 2002138 ) { Scene00042( player ); }
//EOBJECT0, null, 0, -1, False
if( actor == 2002137 ) { Scene00044( player ); }
//ACTOR2, null, 0, -1, False
if( actor == 1006413 ) { Scene00046( player ); }
//ACTOR3, null, 0, -1, False
if( actor == 1006414 ) { Scene00047( player ); }
//EOBJECT5, null, 0, -1, False
if( actor == 2002678 ) { Scene00048( player ); }
//EOBJECT6, null, 0, -1, False
if( actor == 2002679 ) { Scene00050( player ); }
//EOBJECT7, null, 0, -1, False
if( actor == 2002680 ) { Scene00052( player ); }
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
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
player.setQuestUI8CH( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR3", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00006( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00005 +1 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](5)Empty:Scene00006 EOBJECT0", getId() );


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


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](7)Empty:Scene00008 EOBJECT1", getId() );


  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00010( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00009 +1 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT2
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 2 );
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](9)Message:Scene00010 EOBJECT2:UI8BH=-2, 1", getId() );

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


//Target: EOBJECT3
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 2 );
}
}
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](11)Empty:Scene00012 EOBJECT3:UI8AL=-2, 1", getId() );


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
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT4
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 2 );
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](13)Message:Scene00014 EOBJECT4:UI8BL=-2, 1", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00016( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00015 +1 ", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](15)Empty:Scene00016 EOBJECT0", getId() );


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


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](17)Empty:Scene00018 EOBJECT1", getId() );


  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00019 ACTOR2", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00020 ACTOR3", getId() );

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


//Target: EOBJECT5
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](21)Empty:Scene00022 EOBJECT5", getId() );


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


//Target: EOBJECT6
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](23)Empty:Scene00024 EOBJECT6", getId() );


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


//Target: EOBJECT7
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](25)Empty:Scene00026 EOBJECT7", getId() );


  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00028( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00027 +1 ", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](27)Talk:Scene00028 ACTOR2:UI8AL=-1, 1", getId() );

    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00030( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00029 +1 ", getId() );

    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](29)Empty:Scene00030 EOBJECT0", getId() );


  }

  void Scene00031( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00032( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00031 +1 ", getId() );

    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](31)Empty:Scene00032 EOBJECT1", getId() );


  }

  void Scene00033( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00033 ACTOR3", getId() );

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


//Target: EOBJECT5
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](34)Empty:Scene00035 EOBJECT5", getId() );


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


//Target: EOBJECT6
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](36)Empty:Scene00037 EOBJECT6", getId() );


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


//Target: EOBJECT7
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](38)Empty:Scene00039 EOBJECT7", getId() );


  }

  void Scene00040( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00041( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00040 +1 ", getId() );

    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](40)Talk, QuestReward, QuestComplete:Scene00041 ACTOR0", getId() );

    player.playScene( getId(), 41, NONE, callback );
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


//Target: EOBJECT1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](42)Empty:Scene00043 EOBJECT1", getId() );


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


//Target: EOBJECT0
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](44)Empty:Scene00045 EOBJECT0", getId() );


  }

  void Scene00046( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00046 ACTOR2", getId() );

    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00047 ACTOR3", getId() );

    player.playScene( getId(), 47, NONE, callback );
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
//no valid quest var detected
//next scene not found

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


//Target: EOBJECT6
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](50)Empty:Scene00051 EOBJECT6", getId() );


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


//Target: EOBJECT7
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](52)Empty:Scene00053 EOBJECT7", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsb802 );
