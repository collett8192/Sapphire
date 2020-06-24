// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ManFst209_00343
// Quest Name: Lord of the Inferno
// Quest ID: 65879
// Start NPC: 1005116
// End NPC: 1005012

using namespace Sapphire;

class ManFst209 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag16
    // GetQuestBitFlag8
    // GetQuestUI8AH
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1005116;
//    static constexpr auto Actor1 = 1004584;
//    static constexpr auto Actor10 = 1004610;
//    static constexpr auto Actor11 = 1004611;
//    static constexpr auto Actor12 = 1005140;
//    static constexpr auto Actor13 = 1005141;
//    static constexpr auto Actor14 = 1005142;
//    static constexpr auto Actor15 = 1005143;
//    static constexpr auto Actor16 = 1005144;
//    static constexpr auto Actor17 = 1005145;
//    static constexpr auto Actor18 = 1005018;
//    static constexpr auto Actor2 = 1004585;
//    static constexpr auto Actor20 = 1005156;
//    static constexpr auto Actor21 = 1005146;
//    static constexpr auto Actor22 = 1005147;
//    static constexpr auto Actor23 = 1005148;
//    static constexpr auto Actor24 = 1005149;
//    static constexpr auto Actor25 = 1005150;
//    static constexpr auto Actor26 = 1005151;
//    static constexpr auto Actor27 = 1005152;
//    static constexpr auto Actor28 = 1005153;
//    static constexpr auto Actor29 = 1005154;
//    static constexpr auto Actor3 = 1004586;
//    static constexpr auto Actor30 = 1005155;
//    static constexpr auto Actor31 = 1005012;
//    static constexpr auto Actor4 = 1004587;
//    static constexpr auto Actor5 = 1005161;
//    static constexpr auto Actor6 = 1005017;
//    static constexpr auto Actor7 = 1004605;
//    static constexpr auto Actor8 = 1004606;
//    static constexpr auto Actor9 = 1004608;
//    static constexpr auto CutManfst20950 = 88;
//    static constexpr auto Eobject0 = 2001592;
//    static constexpr auto EventActionWaitingShor = 11;
//    static constexpr auto Instancedungeon0 = 20001;
//    static constexpr auto Poprange0 = 4165046;
//    static constexpr auto Poprange1 = 4156164;
//    static constexpr auto Poprange2 = 4148347;
//    static constexpr auto Questbattle0 = 45;
//    static constexpr auto Territorytype0 = 275;
//    static constexpr auto Territorytype1 = 146;
//    static constexpr auto UnlockAddNewContentToCf = 3702;
//    static constexpr auto UnlockImageDungeon = 77;

  public:
    ManFst209() : Sapphire::ScriptAPI::EventScript( 65879 ){}; 
    ~ManFst209() = default; 

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
if( actor == 1004584 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1004585 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1004586 ) { Scene00004( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1004587 ) { Scene00005( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1005161 ) { Scene00006( player ); }
break;
}
case 2:{
player.sendUrgent( "This scene contains quest battle." );
player.sendUrgent( "If stuck in black loading screen, enter and exit \"/gpose\" to get rid of it." );
//EOBJECT0, UI8AL, 1, -2, False
if( actor == 2001592 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00008( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1004584 ) { Scene00009( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1004585 ) { Scene00010( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1004586 ) { Scene00011( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1004587 ) { Scene00012( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1005161 ) { Scene00013( player ); }
break;
}
case 3:{
//ACTOR6, UI8AL, 1, -2, False
if( actor == 1005017 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00014( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1004605 ) { Scene00015( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1004606 ) { Scene00016( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1004608 ) { Scene00017( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1004610 ) { Scene00018( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1004611 ) { Scene00019( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1005140 ) { Scene00020( player ); }
//ACTOR13, null, 0, -2, False
if( actor == 1005141 ) { Scene00021( player ); }
//ACTOR14, null, 0, -2, False
if( actor == 1005142 ) { Scene00022( player ); }
//ACTOR15, null, 0, -2, False
if( actor == 1005143 ) { Scene00023( player ); }
//ACTOR16, null, 0, -2, False
if( actor == 1005144 ) { Scene00024( player ); }
//ACTOR17, null, 0, -2, False
if( actor == 1005145 ) { Scene00025( player ); }
//ACTOR18, null, 0, -2, False
if( actor == 1005018 ) { Scene00026( player ); }
break;
}
case 4:{
//ACTOR7, null, 0, -2, False
if( actor == 1004605 ) { Scene00027( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1004606 ) { Scene00028( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1004608 ) { Scene00029( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1004610 ) { Scene00030( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1004611 ) { Scene00031( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1005017 ) { Scene00032( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1005140 ) { Scene00033( player ); }
//ACTOR13, null, 0, -2, False
if( actor == 1005141 ) { Scene00034( player ); }
//ACTOR14, null, 0, -2, False
if( actor == 1005142 ) { Scene00035( player ); }
//ACTOR15, null, 0, -2, False
if( actor == 1005143 ) { Scene00036( player ); }
//ACTOR16, null, 0, -2, False
if( actor == 1005144 ) { Scene00037( player ); }
//ACTOR17, null, 0, -2, False
if( actor == 1005145 ) { Scene00038( player ); }
//ACTOR18, null, 0, -2, False
if( actor == 1005018 ) { Scene00039( player ); }
break;
}
case 5:{
//ACTOR20, UI8AL, 1, -2, False
if( actor == 1005156 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00040( player ); }
//ACTOR21, null, 0, -2, False
if( actor == 1005146 ) { Scene00041( player ); }
//ACTOR22, null, 0, -2, False
if( actor == 1005147 ) { Scene00042( player ); }
//ACTOR23, null, 0, -2, False
if( actor == 1005148 ) { Scene00043( player ); }
//ACTOR24, null, 0, -2, False
if( actor == 1005149 ) { Scene00044( player ); }
//ACTOR25, null, 0, -2, False
if( actor == 1005150 ) { Scene00045( player ); }
//ACTOR26, null, 0, -2, False
if( actor == 1005151 ) { Scene00046( player ); }
//ACTOR27, null, 0, -2, False
if( actor == 1005152 ) { Scene00047( player ); }
//ACTOR28, null, 0, -2, False
if( actor == 1005153 ) { Scene00048( player ); }
//ACTOR29, null, 0, -2, False
if( actor == 1005154 ) { Scene00049( player ); }
//ACTOR30, null, 0, -2, False
if( actor == 1005155 ) { Scene00050( player ); }
break;
}
case 255:{
//ACTOR31, null, 0, -2, False
if( actor == 1005012 ) { Scene00051( player ); }
//ACTOR21, null, 0, -2, False
if( actor == 1005146 ) { Scene00053( player ); }
//ACTOR22, null, 0, -2, False
if( actor == 1005147 ) { Scene00054( player ); }
//ACTOR23, null, 0, -2, False
if( actor == 1005148 ) { Scene00055( player ); }
//ACTOR24, null, 0, -2, False
if( actor == 1005149 ) { Scene00056( player ); }
//ACTOR25, null, 0, -2, False
if( actor == 1005150 ) { Scene00057( player ); }
//ACTOR26, null, 0, -2, False
if( actor == 1005151 ) { Scene00058( player ); }
//ACTOR27, null, 0, -2, False
if( actor == 1005152 ) { Scene00059( player ); }
//ACTOR28, null, 0, -2, False
if( actor == 1005153 ) { Scene00060( player ); }
//ACTOR29, null, 0, -2, False
if( actor == 1005154 ) { Scene00061( player ); }
//ACTOR30, null, 0, -2, False
if( actor == 1005155 ) { Scene00062( player ); }
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
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
if( result.param2 == 1 ){
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
Scene00014( player );
}
}
    };
player.sendDebug( "questId: {}, calling QuestBattle, YesNo:Scene00008 EOBJECT0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR1", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR2", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00011 ACTOR3", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00012 ACTOR4", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00013 ACTOR5", getId() );


  }

  void Scene00014( Entity::Player& player )
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
player.sendDebug( "questId: {}, calling Talk, Message:Scene00014 ACTOR6:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 ACTOR7", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {


//Target: ACTOR8
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00016 ACTOR8", getId() );


  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ACTOR9", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 ACTOR10", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {


//Target: ACTOR11
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00019 ACTOR11", getId() );


  }

  void Scene00020( Entity::Player& player )
  {


//Target: ACTOR12
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00020 ACTOR12", getId() );


  }

  void Scene00021( Entity::Player& player )
  {


//Target: ACTOR13
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00021 ACTOR13", getId() );


  }

  void Scene00022( Entity::Player& player )
  {


//Target: ACTOR14
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00022 ACTOR14", getId() );


  }

  void Scene00023( Entity::Player& player )
  {


//Target: ACTOR15
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00023 ACTOR15", getId() );


  }

  void Scene00024( Entity::Player& player )
  {


//Target: ACTOR16
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00024 ACTOR16", getId() );


  }

  void Scene00025( Entity::Player& player )
  {


//Target: ACTOR17
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00025 ACTOR17", getId() );


  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR18
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00026 ACTOR18", getId() );

    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//no valid quest var detected
player.updateQuest( getId(), 5 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00027 ACTOR7", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {


//Target: ACTOR8
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00028 ACTOR8", getId() );


  }

  void Scene00029( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//no valid quest var detected
player.updateQuest( getId(), 5 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00029 ACTOR9", getId() );

    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
//no valid quest var detected
player.updateQuest( getId(), 5 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00030 ACTOR10", getId() );

    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {


//Target: ACTOR11
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00031 ACTOR11", getId() );


  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//no valid quest var detected
player.updateQuest( getId(), 5 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00032 ACTOR6", getId() );

    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {


//Target: ACTOR12
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00033 ACTOR12", getId() );


  }

  void Scene00034( Entity::Player& player )
  {


//Target: ACTOR13
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00034 ACTOR13", getId() );


  }

  void Scene00035( Entity::Player& player )
  {


//Target: ACTOR14
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00035 ACTOR14", getId() );


  }

  void Scene00036( Entity::Player& player )
  {


//Target: ACTOR15
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00036 ACTOR15", getId() );


  }

  void Scene00037( Entity::Player& player )
  {


//Target: ACTOR16
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00037 ACTOR16", getId() );


  }

  void Scene00038( Entity::Player& player )
  {


//Target: ACTOR17
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00038 ACTOR17", getId() );


  }

  void Scene00039( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR18
//no valid quest var detected
if( result.param2 == 1 ){
player.updateQuest( getId(), 5 );
}
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00039 ACTOR18", getId() );

    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR20
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00040 ACTOR20:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {


//Target: ACTOR21
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00041 ACTOR21", getId() );


  }

  void Scene00042( Entity::Player& player )
  {


//Target: ACTOR22
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00042 ACTOR22", getId() );


  }

  void Scene00043( Entity::Player& player )
  {


//Target: ACTOR23
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00043 ACTOR23", getId() );


  }

  void Scene00044( Entity::Player& player )
  {


//Target: ACTOR24
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00044 ACTOR24", getId() );


  }

  void Scene00045( Entity::Player& player )
  {


//Target: ACTOR25
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00045 ACTOR25", getId() );


  }

  void Scene00046( Entity::Player& player )
  {


//Target: ACTOR26
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00046 ACTOR26", getId() );


  }

  void Scene00047( Entity::Player& player )
  {


//Target: ACTOR27
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00047 ACTOR27", getId() );


  }

  void Scene00048( Entity::Player& player )
  {


//Target: ACTOR28
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00048 ACTOR28", getId() );


  }

  void Scene00049( Entity::Player& player )
  {


//Target: ACTOR29
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00049 ACTOR29", getId() );


  }

  void Scene00050( Entity::Player& player )
  {


//Target: ACTOR30
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00050 ACTOR30", getId() );


  }

  void Scene00051( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 )
Scene00052( player );
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward:Scene00051 +1 ", getId() );

    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR31
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
    };
player.sendDebug( "questId: {}, calling [sub:Complete](51)CutScene, QuestComplete:Scene00052 ACTOR31", getId() );

    player.playScene( getId(), 52, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00053( Entity::Player& player )
  {


//Target: ACTOR21
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00053 ACTOR21", getId() );


  }

  void Scene00054( Entity::Player& player )
  {


//Target: ACTOR22
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00054 ACTOR22", getId() );


  }

  void Scene00055( Entity::Player& player )
  {


//Target: ACTOR23
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00055 ACTOR23", getId() );


  }

  void Scene00056( Entity::Player& player )
  {


//Target: ACTOR24
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00056 ACTOR24", getId() );


  }

  void Scene00057( Entity::Player& player )
  {


//Target: ACTOR25
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00057 ACTOR25", getId() );


  }

  void Scene00058( Entity::Player& player )
  {


//Target: ACTOR26
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00058 ACTOR26", getId() );


  }

  void Scene00059( Entity::Player& player )
  {


//Target: ACTOR27
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00059 ACTOR27", getId() );


  }

  void Scene00060( Entity::Player& player )
  {


//Target: ACTOR28
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00060 ACTOR28", getId() );


  }

  void Scene00061( Entity::Player& player )
  {


//Target: ACTOR29
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00061 ACTOR29", getId() );


  }

  void Scene00062( Entity::Player& player )
  {


//Target: ACTOR30
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00062 ACTOR30", getId() );


  }

};

EXPOSE_SCRIPT( ManFst209 );
