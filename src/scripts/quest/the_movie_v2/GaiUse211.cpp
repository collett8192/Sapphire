// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse211_01355
// Quest Name: Writhing in the Dark
// Quest ID: 66891
// Start NPC: 1008663
// End NPC: 1008565

using namespace Sapphire;

class GaiUse211 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL
    // GetQuestUI8CH
    // GetQuestUI8CL
    // GetQuestUI8DH
    // GetQuestUI8DL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      Seq2 = 2,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1008663;
//    static constexpr auto Actor1 = 1008662;
//    static constexpr auto Actor10 = 1008672;
//    static constexpr auto Actor11 = 1008673;
//    static constexpr auto Actor12 = 1008674;
//    static constexpr auto Actor13 = 1008675;
//    static constexpr auto Actor14 = 1008541;
//    static constexpr auto Actor15 = 1008705;
//    static constexpr auto Actor16 = 1008565;
//    static constexpr auto Actor2 = 1008664;
//    static constexpr auto Actor3 = 1008665;
//    static constexpr auto Actor4 = 1008666;
//    static constexpr auto Actor5 = 1008667;
//    static constexpr auto Actor6 = 1008668;
//    static constexpr auto Actor7 = 1008669;
//    static constexpr auto Actor8 = 1008670;
//    static constexpr auto Actor9 = 1008671;
//    static constexpr auto BgmNothing = 1;
//    static constexpr auto CutSceneN01 = 464;
//    static constexpr auto CutSceneN02 = 465;
//    static constexpr auto CutSceneN03 = 466;
//    static constexpr auto Enemy0 = 4622527;
//    static constexpr auto Enemy1 = 4622528;
//    static constexpr auto Enemy2 = 4622530;
//    static constexpr auto Enemy3 = 4622531;
//    static constexpr auto Enemy4 = 4622533;
//    static constexpr auto Enemy5 = 4622534;
//    static constexpr auto Enemy6 = 4622536;
//    static constexpr auto Enemy7 = 4622537;
//    static constexpr auto Enemy8 = 4622538;
//    static constexpr auto Enemy9 = 4622539;
//    static constexpr auto Eobject0 = 2003579;
//    static constexpr auto Eobject1 = 2003580;
//    static constexpr auto Eobject2 = 2003581;
//    static constexpr auto Eobject3 = 2003582;
//    static constexpr auto Eobject4 = 2003583;
//    static constexpr auto Eobject5 = 2003584;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2001212;

  public:
    GaiUse211() : Sapphire::ScriptAPI::EventScript( 66891 ){}; 
    ~GaiUse211() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1008663 ) { Scene00000( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1008662 ) { Scene00002( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1008664 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008665 ) { Scene00004( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008666 ) { Scene00005( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1008667 ) { Scene00006( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1008668 ) { Scene00007( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1008669 ) { Scene00008( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1008670 ) { Scene00009( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1008671 ) { Scene00010( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1008672 ) { Scene00011( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1008673 ) { Scene00012( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1008674 ) { Scene00013( player ); }
//ACTOR13, null, 0, -2, False
if( actor == 1008675 ) { Scene00014( player ); }
//ACTOR14, null, 0, -2, False
if( actor == 1008541 ) { Scene00015( player ); }
break;
}
case 1:{
//EOBJECT0, null, 0, -2, False
if( actor == 2003579 ) { Scene00016( player ); }
//if( actorId == 4622527 && player.getQuestUI8DH( getId() ) != 2 ) { Scene?????( player ); }
//if( actorId == 4622528 && player.getQuestUI8DH( getId() ) != 2 ) { Scene?????( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2003580 ) { Scene00017( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2003581 ) { Scene00019( player ); }
//if( actorId == 4622533 && player.getQuestUI8BH( getId() ) != 2 ) { Scene?????( player ); }
//if( actorId == 4622534 && player.getQuestUI8BH( getId() ) != 2 ) { Scene?????( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2003582 ) { Scene00021( player ); }
//if( actorId == 4622536 && player.getQuestUI8BL( getId() ) != 1 ) { Scene?????( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2003583 ) { Scene00023( player ); }
//if( actorId == 4622537 && player.getQuestUI8CH( getId() ) != 1 ) { Scene?????( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2003584 ) { Scene00025( player ); }
//if( actorId == 4622538 && player.getQuestUI8CL( getId() ) != 2 ) { Scene?????( player ); }
//if( actorId == 4622539 && player.getQuestUI8CL( getId() ) != 2 ) { Scene?????( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1008662 ) { Scene00027( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1008663 ) { Scene00029( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1008664 ) { Scene00030( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008665 ) { Scene00031( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008666 ) { Scene00032( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1008667 ) { Scene00033( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1008668 ) { Scene00034( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1008669 ) { Scene00035( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1008670 ) { Scene00036( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1008671 ) { Scene00037( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1008672 ) { Scene00038( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1008673 ) { Scene00039( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1008674 ) { Scene00040( player ); }
//ACTOR13, null, 0, -2, False
if( actor == 1008675 ) { Scene00041( player ); }
//ACTOR14, null, 0, -2, False
if( actor == 1008541 ) { Scene00042( player ); }
break;
}
case 2:{
Scene00043( player );
break;
}
case 255:{
Scene00044( player );
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
player.setQuestUI8DL( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ACTOR0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {


//Target: ACTOR1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00002 ACTOR1", getId() );


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


//Target: ACTOR9
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR9", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


//Target: ACTOR10
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00011 ACTOR10", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR11
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00012 ACTOR11", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


//Target: ACTOR12
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00013 ACTOR12", getId() );


  }

  void Scene00014( Entity::Player& player )
  {


//Target: ACTOR13
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00014 ACTOR13", getId() );


  }

  void Scene00015( Entity::Player& player )
  {


//Target: ACTOR14
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00015 ACTOR14", getId() );


  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00016 EOBJECT0", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00017 +1 ", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](17)Inventory:Scene00018 EOBJECT1", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00019 +1 ", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](19)Inventory:Scene00020 EOBJECT2", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00021 +1 ", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](21)Inventory:Scene00022 EOBJECT3", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00023 +1 ", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](23)Inventory:Scene00024 EOBJECT4", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00025 +1 ", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](25)Inventory:Scene00026 EOBJECT5", getId() );

    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00027 +1 ", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](27)Empty:Scene00028 ACTOR1", getId() );

    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//no valid quest var detected
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00029 ACTOR0", getId() );

    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {


//Target: ACTOR2
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00030 ACTOR2", getId() );


  }

  void Scene00031( Entity::Player& player )
  {


//Target: ACTOR3
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00031 ACTOR3", getId() );


  }

  void Scene00032( Entity::Player& player )
  {


//Target: ACTOR4
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00032 ACTOR4", getId() );


  }

  void Scene00033( Entity::Player& player )
  {


//Target: ACTOR5
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00033 ACTOR5", getId() );


  }

  void Scene00034( Entity::Player& player )
  {


//Target: ACTOR6
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00034 ACTOR6", getId() );


  }

  void Scene00035( Entity::Player& player )
  {


//Target: ACTOR7
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00035 ACTOR7", getId() );


  }

  void Scene00036( Entity::Player& player )
  {


//Target: ACTOR8
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00036 ACTOR8", getId() );


  }

  void Scene00037( Entity::Player& player )
  {


//Target: ACTOR9
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00037 ACTOR9", getId() );


  }

  void Scene00038( Entity::Player& player )
  {


//Target: ACTOR10
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00038 ACTOR10", getId() );


  }

  void Scene00039( Entity::Player& player )
  {


//Target: ACTOR11
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00039 ACTOR11", getId() );


  }

  void Scene00040( Entity::Player& player )
  {


//Target: ACTOR12
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00040 ACTOR12", getId() );


  }

  void Scene00041( Entity::Player& player )
  {


//Target: ACTOR13
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00041 ACTOR13", getId() );


  }

  void Scene00042( Entity::Player& player )
  {


//Target: ACTOR14
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00042 ACTOR14", getId() );


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
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling CutScene, QuestReward, QuestComplete, FadeOut:Scene00044 ", getId() );

    player.playScene( getId(), 44, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( GaiUse211 );
