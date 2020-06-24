// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb311_00852
// Quest Name: Bird's-eye View
// Quest ID: 66388
// Start NPC: 1006273
// End NPC: 1006273

using namespace Sapphire;

class GaiUsb311 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1006273;
//    static constexpr auto Actor1 = 1006320;
//    static constexpr auto Actor10 = 1007554;
//    static constexpr auto Actor11 = 1007555;
//    static constexpr auto Actor12 = 1007556;
//    static constexpr auto Actor13 = 1007557;
//    static constexpr auto Actor14 = 1007558;
//    static constexpr auto Actor2 = 1006321;
//    static constexpr auto Actor3 = 1006322;
//    static constexpr auto Actor4 = 1007549;
//    static constexpr auto Actor5 = 1007550;
//    static constexpr auto Actor6 = 1007551;
//    static constexpr auto Actor7 = 1007552;
//    static constexpr auto Actor8 = 1007553;
//    static constexpr auto Actor9 = 1006323;
//    static constexpr auto Eobject0 = 2002064;
//    static constexpr auto Eobject1 = 2002065;
//    static constexpr auto Eobject2 = 2002066;
//    static constexpr auto Eobject3 = 2002677;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000661;

  public:
    GaiUsb311() : Sapphire::ScriptAPI::EventScript( 66388 ){}; 
    ~GaiUsb311() = default; 

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
if( actor == 1006320 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006321 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006322 ) { Scene00004( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007549 ) { Scene00005( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1007550 ) { Scene00006( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1007551 ) { Scene00007( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1007552 ) { Scene00008( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1007553 ) { Scene00009( player ); }
break;
}
case 2:{
//EOBJECT0, UI8AL, 1, -2, False
if( actor == 2002064 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00010( player ); }
//EOBJECT1, UI8BH, 1, -2, False
if( actor == 2002065 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00011( player ); }
//EOBJECT2, UI8BL, 1, -2, False
if( actor == 2002066 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00012( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006320 ) { Scene00013( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006321 ) { Scene00014( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006322 ) { Scene00015( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007549 ) { Scene00016( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1007550 ) { Scene00017( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1007551 ) { Scene00018( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1007552 ) { Scene00019( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1007553 ) { Scene00020( player ); }
//EOBJECT3, UI8CH, 1, -2, False
if( actor == 2002677 && player.getQuestUI8CH( getId() ) != 1 ) { Scene00021( player ); }
break;
}
case 3:{
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1006320 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00022( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006322 ) { Scene00023( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1006323 ) { Scene00024( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1007554 ) { Scene00025( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1007555 ) { Scene00026( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1007556 ) { Scene00027( player ); }
//ACTOR13, null, 0, -2, False
if( actor == 1007557 ) { Scene00028( player ); }
//ACTOR14, null, 0, -2, False
if( actor == 1007558 ) { Scene00029( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002064 ) { Scene00030( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002065 ) { Scene00031( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002066 ) { Scene00032( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002677 ) { Scene00033( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1006273 ) { Scene00042( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006320 ) { Scene00043( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006322 ) { Scene00044( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1006323 ) { Scene00045( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1007554 ) { Scene00046( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1007555 ) { Scene00047( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1007556 ) { Scene00048( player ); }
//ACTOR13, null, 0, -2, False
if( actor == 1007557 ) { Scene00049( player ); }
//ACTOR14, null, 0, -2, False
if( actor == 1007558 ) { Scene00050( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002064 ) { Scene00051( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002065 ) { Scene00052( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002066 ) { Scene00053( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002677 ) { Scene00054( player ); }
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
player.setQuestUI8BH( getId(), 1 );
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
player.setQuestUI8CL( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 2, NONE, callback );
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


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00005 ACTOR4", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00006 ACTOR5", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00007 ACTOR6", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00008 ACTOR7", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR8
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR8", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 3 );
}
}
}
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00010 EOBJECT0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {


//Target: EOBJECT1
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 3 );
}
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00011 EOBJECT1:UI8BH=-2, 1", getId() );


  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT2
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 3 );
}
}
}
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00012 EOBJECT2:UI8BL=-2, 1", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {


//Target: ACTOR1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00013 ACTOR1", getId() );


  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00014 ACTOR2", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00015 ACTOR3", getId() );


  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 ACTOR4", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00017 ACTOR5", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00018 ACTOR6", getId() );


  }

  void Scene00019( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00019 ACTOR7", getId() );


  }

  void Scene00020( Entity::Player& player )
  {


//Target: ACTOR8
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00020 ACTOR8", getId() );


  }

  void Scene00021( Entity::Player& player )
  {


//Target: EOBJECT3
player.setQuestUI8CH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 3 );
}
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00021 EOBJECT3:UI8CH=-2, 1", getId() );


  }

  void Scene00022( Entity::Player& player )
  {


//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00022 ACTOR1:UI8AL=-2, 1", getId() );


  }

  void Scene00023( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00023 ACTOR3", getId() );


  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00024 ACTOR9", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {


//Target: ACTOR10
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00025 ACTOR10", getId() );


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


//Target: ACTOR12
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00027 ACTOR12", getId() );


  }

  void Scene00028( Entity::Player& player )
  {


//Target: ACTOR13
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00028 ACTOR13", getId() );


  }

  void Scene00029( Entity::Player& player )
  {


//Target: ACTOR14
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00029 ACTOR14", getId() );


  }

  void Scene00030( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00030 EOBJECT0", getId() );


  }

  void Scene00031( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00031 EOBJECT1", getId() );


  }

  void Scene00032( Entity::Player& player )
  {


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00032 EOBJECT2", getId() );


  }

  void Scene00033( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00033 EOBJECT3", getId() );


  }

  void Scene00034( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00034 ", getId() );


  }

  void Scene00035( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00035 ", getId() );


  }

  void Scene00036( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00036 ", getId() );


  }

  void Scene00037( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00037 ", getId() );


  }

  void Scene00038( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00038 ", getId() );


  }

  void Scene00039( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00039 ", getId() );


  }

  void Scene00040( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00040 ", getId() );


  }

  void Scene00041( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00041 ", getId() );


  }

  void Scene00042( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00042 ACTOR0", getId() );

    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00043 ACTOR1", getId() );

    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {


//Target: ACTOR3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00044 ACTOR3", getId() );


  }

  void Scene00045( Entity::Player& player )
  {


//Target: ACTOR9
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00045 ACTOR9", getId() );


  }

  void Scene00046( Entity::Player& player )
  {


//Target: ACTOR10
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00046 ACTOR10", getId() );


  }

  void Scene00047( Entity::Player& player )
  {


//Target: ACTOR11
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00047 ACTOR11", getId() );


  }

  void Scene00048( Entity::Player& player )
  {


//Target: ACTOR12
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00048 ACTOR12", getId() );


  }

  void Scene00049( Entity::Player& player )
  {


//Target: ACTOR13
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00049 ACTOR13", getId() );


  }

  void Scene00050( Entity::Player& player )
  {


//Target: ACTOR14
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00050 ACTOR14", getId() );


  }

  void Scene00051( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00051 EOBJECT0", getId() );


  }

  void Scene00052( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00052 EOBJECT1", getId() );


  }

  void Scene00053( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00053 EOBJECT2", getId() );


  }

  void Scene00054( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00054 EOBJECT3", getId() );


  }

  void Scene00055( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00055 ", getId() );


  }

  void Scene00056( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00056 ", getId() );


  }

  void Scene00057( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00057 ", getId() );


  }

  void Scene00058( Entity::Player& player )
  {


//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00058 ", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsb311 );
